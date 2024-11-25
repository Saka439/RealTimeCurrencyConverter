#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

typedef map<string, double> TauxDeChange;

// Fonction de callback pour gérer la réponse HTTP
size_t writeCallback(void* contents, size_t size, size_t nmemb, string* s) {
    size_t newLength = size * nmemb;
    try {
        s->append((char*)contents, newLength);
    }
    catch (bad_alloc& e) {
        return 0;
    }
    return newLength;
}


string chargerCleAPI() {
    ifstream env_file(".env");
    string line;
    while (getline(env_file, line)) {
        if (line.find("API_KEY=") == 0) {
            return line.substr(8);  
        }
    }
    cerr << "Erreur : clé API non trouvée dans .env" << endl;
    return "";
}

// Fonction pour obtenir les taux de change en temps réel depuis une API
TauxDeChange obtenirTauxDeChange(const string& api_key) {
    CURL* curl;
    CURLcode res;
    string readBuffer;
    TauxDeChange taux;

    string url = "https://openexchangerates.org/api/latest.json?app_id=" + api_key;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res == CURLE_OK) {
            json j = json::parse(readBuffer);
            if (j.contains("rates")) {
                for (auto& el : j["rates"].items()) {
                    taux[el.key()] = el.value().get<double>();
                }
            }
        }
        else {
            cout << "Erreur lors de la récupération des données : " << curl_easy_strerror(res) << endl;
        }
    }
    return taux;
}


double convertir(double montant, const string& devise_source, const string& devise_destination, TauxDeChange& taux) {
    if (taux.find(devise_source) == taux.end() || taux.find(devise_destination) == taux.end()) {
        cout << "Devise non prise en charge." << endl;
        return -1;
    }
    double taux_conversion = taux[devise_destination] / taux[devise_source];
    return montant * taux_conversion;
}

int main() {
    string api_key = chargerCleAPI();
    if (api_key.empty()) {
        cerr << "Erreur : Impossible de charger la clé API." << endl;
        return 1;
    }

    
    TauxDeChange taux = obtenirTauxDeChange(api_key);

    if (taux.empty()) {
        cout << "Impossible d'obtenir les taux de change." << endl;
        return 1;
    }

    double montant;
    string devise_source, devise_destination;
    cout << "Entrez le montant : ";
    cin >> montant;
    cout << "Entrez la devise source (par exemple, CAD) : ";
    cin >> devise_source;
    cout << "Entrez la devise de destination (par exemple, USD,XOF,EUR,DZD,MAD,GBP) : ";
    cin >> devise_destination;

    double montant_converti = convertir(montant, devise_source, devise_destination, taux);

    if (montant_converti != -1) {
        cout << "Le montant converti est : " << montant_converti << " " << devise_destination << endl;
    }

    return 0;
}
