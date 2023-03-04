# Huitième séance du 3 Mars 2023

Durant ma huitième et dernière séance j'ai travaillé sur une version améliorée de notre projet.
Au départ on avait décidé de garder le projet qu'on avait réalisé et en faire un deuxième à côté mais amélioré.

- #### Travail sur un la version 2 du projet

Je suis allé au fablab pour souder un nouvel écran, souder les led avec les résistances pour les nouveaux lampadaires et réaliser une nappe pour que tous les fils soient bien reliés entre-eux. De plus j’ai découpé une nouvelle boîte en bois même s’il y a eu quelques soucis à la faire à cause des dimensions et du manque de planches en bois. Au final le tout a été réalisé:

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/nouvel_ecran.png" alt="écran lcd" 
height="300"> <img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/boite_n2.png" alt="boite 2" height="300">

Malheureusement cette deuxième version ne peut pas aboutir car on a eu un manque de temps...

- #### Travail sur l'entrée du parking et matrice led

Ensuite j’ai récupéré une matrice led 8x8 qui sera placée à l’entrée du parking et qui affichera tout simplement le nombre de places disponibles. Dans le cas où il n’y aurait aucune place disponible toute la matrice led se mettrait à clignoter. Pour cela j’ai alors dû utiliser [ce site](https://ijhack.nl/page/led-matrix-generator) pour pouvoir coder chaque led de la matrice qui sera indiqué en binaire pour pouvoir après réécrire chaque ligne en hexadécimal pour mon code. Dans le GitHub il y a le code pour la matrice simple ici et la versione unifié que j’ai fait en intégrant aussi le parking ici. Voici le résultat que cela donne:

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/chiffre1.png" alt="chiffre 1 site" 
height="150"> <img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/chiffre2.png" alt="chiffre 2 site" height="150"> <img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/chiffre3.png" alt="chiffre 3 site" height="150"> <img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/chiffre4.png" alt="chiffre 4 site" height="150">

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/mat_1.png" alt="matrice 1" 
height="300"> <img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/mat_2.png" alt="matrice 2" height="300"> <img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/mat_3.png" alt="matrice 3" height="300"> <img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/mat_4.png" alt="matrice 4" height="300">

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/2places.png" alt="2 places parking" 
height="300"> <img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/4places.png" alt="4 places parking" height="300"> <img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/parking_complet.png" alt="parking complet" height="300"> <img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/parking_complet2.png" alt="parking complet" height="300">

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/boite_matrice_svg.png" alt="boite svg" height="300">

De plus j’ai réaliser un fichier svg pour réaliser une petite boîte qui va contenir la matrice led et qu’on va placer à l’entrée du parking. Voici le fichier ainsi que le résultat final avec un trou dans la boîte pour voir la matrice:

- #### Travail sur détecteur de poussière

Grâce à mon professeur j’ai compris un peu mieux comment utiliser le module de capteur de poussière DSM501A pm2,5. On a pu faire ensemble le montage et tester ce capteur grâce à un code trouvé en ligne. Le détecteur renvoie le nombre de particules pour 1/100 de pied cube (environ 0,03 mètres cubes). Voici la photo du montage:
J’ai réussi à afficher les valeur sur l’écran lcd que j’avais soudé préalablement du coup j’ai pu unifier cette composante avec le code de la station météo et des lampadaires, le code est ici.

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/detecteur_particules.png" alt="détecteur particules" height="300">


<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/lampadaire_eteint.jpeg" alt="ensemble du projet" 
height="300">
