RealTimeCurrencyConverter
RealTimeCurrencyConverter est un programme C++ qui permet de convertir des devises en temps réel en utilisant l'API de Open Exchange Rates. Ce projet utilise les bibliothèques curl pour les requêtes HTTP et nlohmann-json pour la gestion des données JSON.

Prérequis
Git doit être installé pour cloner le dépôt.
CMake et vcpkg doivent être configurés pour la gestion des dépendances.
Un compte sur Open Exchange Rates pour obtenir une clé API gratuite.
Installation des dépendances
Assurez-vous que vcpkg est installé et ajouté à votre PATH.

Installez les dépendances nécessaires :

bash

vcpkg install curl nlohmann-json
Étapes d'installation
Cloner le dépôt

bash

git clone https://github.com/Saka439/RealTimeCurrencyConverter.git
cd RealTimeCurrencyConverter
Configurer les bibliothèques avec CMake

Si vous utilisez vcpkg comme gestionnaire de packages, configurez le projet avec :

bash

mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=[path_to_vcpkg]/scripts/buildsystems/vcpkg.cmake
Remplacez [path_to_vcpkg] par le chemin où vcpkg est installé.

Compiler le projet

bash
Copier le code
cmake --build .
Configurer la clé API

Créez un fichier .env dans le répertoire racine avec votre clé API d'Open Exchange Rates :

makefile

API_KEY=your_api_key_here
Utilisation
Exécutez le programme

bash

./ExchangeRates
Entrez les informations demandées

Le montant à convertir.
La devise source (ex. : USD).
La devise de destination (ex. : EUR, XOF, etc.).
Le programme calculera et affichera le montant converti en temps réel.

Exemples

Entrez le montant : 200
Entrez la devise source (par exemple, USD) : USD
Entrez la devise de destination (par exemple, EUR) : EUR
Le montant converti est : 183.34 EUR
Remarques
Assurez-vous d'avoir une connexion internet active pour que le programme puisse obtenir les taux de change actuels.
Le fichier .env contenant la clé API ne doit pas être partagé publiquement pour des raisons de sécurité.
Contribuer
Les contributions sont les bienvenues ! N'hésitez pas à ouvrir une issue ou une pull request pour proposer des améliorations.

Licence
Ce projet est sous licence MIT.
