# Sixième séance du 10 Février 2023

Durant ma sixième séance j'ai:

- #### Travail sur la base du projet

Réalisé des trous sur la maquette en bois de deux façon différentes:
- ###### grâce à une perceuse 
- ###### grâce à la découpeuse laser. J'ai modélisé des carrés/rectangles un fichier .svg via le logiciel Inkscape et après avoir mis la planche en bois dans la machine et positionné le laser pour indiquer où couper, j'ai pu obtenir des coupes parfaites.  

Une fois cela fait, j'ai colorier les bords de la ville en noir comme vous pouvez le voir ici:
<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/planche_base_noir.jpeg" alt="base du projet fin" 
height="300">

- #### Re-soudage d'un capteur de distance

La semaine dernière j'avais soudé des capteurs de distance car leur forme m'intéressait sauf que je me suis rendu compte en les testant aujourd'hui que l'un que j'avais fait ne fonctionnait plus, du coup j'ai dû en faire un nouveau.

- #### Collage des lampadaires et prolongation des fils

Le reste de la séance j’ai cherché comment pouvoir connecter deux écran lcd sur une seule carte grâce au module i2c. Il a fallu souder dans l’un des deux modules une encoche (ici la A0) afin de lui changer d’adresse. Par défaut l’adresse d’un écran avec le module i2c est 0x27 mais en soudant l’adresse de la deuxième carte a changé en 0x26. On peut voir la soudure et l'adresse de chaque écrans que j'ai récupéré grâce au scanneur i2c dont le code est [ici](https://github.com/villeautonome/Ville-Connectee/tree/main/rapport%20séances/Francesco/codes/I2C_scanner.ino): 

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/ecrans2_A0.jpeg" alt="écrans soudé sur A0" 
height="300">         <img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/I2Cscanner.png" alt="résultat scanner I2C" 
height="150"> 

Une fois l’opération terminée j’ai effectué le montage est j’ai vérifié si on avait bien deux affichages différents dans les cartes grâce à un [code test](https://github.com/villeautonome/Ville-Connectee/tree/main/rapport%20séances/Francesco/codes/test_2_ecrans.ino). On peut voir le montage qu'il faut faire ainsi que le résulta: 

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/montage_2ecrans.png" alt="montage 2 écrans" 
height="300"> 
<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/test_2ecrans.jpeg" alt="test 2 écrans soudé" 
height="300">  

J’ai donc unifié le code que j’avais écrit avec celui de mon binôme puisque maintenant on peut utilisé une seule carte arduino uno étant donné que notre problème principal était le fait qu’on n’arrivait pas à utiliser deux écrans relié à une même carte arduino. Il y a le code [ici](https://github.com/villeautonome/Ville-Connectee/tree/main/rapport%20séances/Francesco/codes/version_unie.ino) et les deux écrans avec ce code ici: 

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/resultat_2ecrans.jpeg" alt="vérification 2 écrans" 
height="300">  
