🌐 RealTimeCurrencyConverter

RealTimeCurrencyConverter est un programme C++ permettant de convertir des devises en temps réel en utilisant l'API de Open Exchange Rates. 

Ce projet repose sur les bibliothèques curl pour les requêtes HTTP et nlohmann-json pour la manipulation des données JSON.


📋 Prérequis
Avant de commencer, assurez-vous que vous disposez des éléments suivants :

Git pour cloner le dépôt.

CMake et vcpkg pour la gestion des dépendances.

Un compte sur Open Exchange Rates pour obtenir une clé API (gratuite).


⚙️ Installation des dépendances

Vérifiez que vcpkg est installé et configuré dans votre PATH.

Installez les bibliothèques nécessaires avec vcpkg :

vcpkg install curl nlohmann-json


🚀 Étapes d'installation

**Clonez le dépôt:

git clone https://github.com/Saka439/RealTimeCurrencyConverter.git

cd RealTimeCurrencyConverter


**Configurez les bibliothèques avec CMake

Si vous utilisez vcpkg comme gestionnaire de packages, configurez le projet comme suit :

mkdir build

cd build

cmake .. -DCMAKE_TOOLCHAIN_FILE=[path_to_vcpkg]/scripts/buildsystems/vcpkg.cmake

Remplacez [path_to_vcpkg] par le chemin de votre installation vcpkg


***Compilez le projet

cmake --build .



**Ajoutez votre clé API

Dans le répertoire racine, créez un fichier nommé .env avec votre clé API d'Open Exchange Rates :


API_KEY=your_api_key_here




🛠️ Utilisation

Exécutez le programme:

./ExchangeRates


Suivez les instructions pour entrer les informations suivantes :

Montant à convertir.

Devise source (par exemple, USD).

Devise de destination (par exemple, EUR, XOF, etc.).

Le programme affichera le montant converti en temps réel



📜 License

Ce projet est sous licence MIT.


