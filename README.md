# ProjetAdresseIP
S2 Projet Adresse IP

Van de Plasse Edwin et Darrestieu Arnaud

Projet de S2, sujet choisi sur l'adressage IP qui pour objective de rentrer une adresse Ip au format X.X.X.X/X et d'en obtenir le type ainsi que sa classe et son nombre de machines connectables.

Liste des méthodes et leur fonction :

main : Exécute globalement le code et écrit dans un fichier le résultat de l'analyse.

getAdresse : Analyse l'adresse reçue pour vérifier sa validité, les caractères tels que les lettre ne devraient pas passer mais on n'arrive pas à gérer cette erreur (utilisation isalpha()).

getClass : Retourne selon le masque la classe de l'adresse IP.

getTypeAdresse : Retourne le type de la classe entrée.

getReseau : Retourne en fonction de l'adresse et du masque le nombre de machines connectables à ce réseau. 
