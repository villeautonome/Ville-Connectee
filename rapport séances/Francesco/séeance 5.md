# Cinquième séance du 3 Février 2023


- ##### Travail sur les led du parking

Durant ma quatrième séance j'ai commencé a découpé chaque led rgb à partir de la bande qu'on avait pour ensuite souder les fils 5V, GND et DO afin de pouvoir les utiliser individuellement, dans un deuxième temps, pour indiquer si une place de parking est disponible ou pas.

- ##### Découpage boîte finale

Grâce à l’oral de présentation du projet on a pu faire le point sur l’ensemble du projet afin de mieux comprendre quel était notre état d’avancement. Les professeurs nous ont bien suggéré de changer la base en bois. Pour cela on a utiliser le site [boxes.py (festi.info)](https://www.festi.info/boxes.py/?language=fr)  pour générer les pièces de la boîte fermée avec des encoches de dimension 29cm le largeur, 40cm de longueur et 10cm de hauteur à découper. On a décidé de faire une boîte car cela est plus pratique pour mettre et cacher les cables et la carte arduino dedant. Voici le fichier obtenu: <img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/ClosedBox.png" alt="pièces de la boite" 
height="300">

On est donc allé au fablab pour découper notre boîte grâce à la découpeuse laser et voici le résultat final:

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/boite.jpeg" alt="boite"
     height="300">


- ##### Utilisation de deux écrans sur une carte Arduino

Ensuite j’ai essayé de comprendre mieux sur internet comment pouvoir connecter deux écrans sur une même carte étant donné que pour l’instant on pensait qu’on ne pouvait pas brancher deux écran sur une même carte. La solution a été de différencier les écrans par des bus différents dans notre code, il faut imposer l'adresse de chaque écrans. Dans le cas montré ci-dessous on met l'écrans 1 sur l'adresse 0x26 et le deuxième sur l'adresse 0x27 (comme je l'avais déjà fait dans mon code pour la station météo où j'avais déclaré mon écrans sur l'adresse 0x27). Un peu comme montré ici:

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/2ecrans.jpeg" alt="code pour deux écrans" height="300">

- ##### Passage piéton

Enfin je me suis concentré sur une partie de notre ville: le passage piéton. J’ai essayé pendant un bon moment d’utiliser le capteur de proximité à infrarouges FC 51 en essayant plusieurs montages/câblages et différents codes mais rien ne fonctionnait. Du coup je me suis informé et décidé d’utiliser un deux autres capteurs à infrarouge, le TCRT5000 et le KY-033:

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/capteurTC.jpeg" alt="capteurTC" 
     height="200">
<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/capteurKY.jpeg" alt="capteurKY" 
     height="200">

J'ai donc écrit le code qui permet d'allumer une led quand le capteur détecte un objet ou du moins quelque chose devant lui, cela simule le passage piéton qui permettra d'allumer une led quand un piéton sera détecter. Voici le montage:

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/obstacle_oui.jpeg" alt="obstacle détecté"
     height="300">
<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/obstacle_non.jpeg" alt="obstacle non détecté" height="300">

On a alors opté d'utiliser ces capteur aussi pour le parking car ils sont moins encombrant (chose importante vu la taille de notre base qu'on a même dû réduire d'1 centimètre).

J'ai alors modifié le code de la station météo en y ajoutant des commentaires et en insérant la partie qui allume la led pour le passage piéton (il est disponible dans le dossier [codes (station_meteo.ino)](https://github.com/villeautonome/Ville-Connectee/tree/main/rapport%20séances/Francesco/codes). Ce code contient donc pour l'instant 3 fonctions pour afficher la date et l'heure sur l'écran, afficher la température et l'humidité à des intervalles de temps, pour allumer la led si le détecteur à infrarouges détecte un objet devant lui.
