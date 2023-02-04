# Cinquième séance du 3 Février 2023

- ##### Travail sur la base du projet

Durant ma cinquième séance j’ai commencé par tracer au crayon les différents éléments sur la base de notre nouvelle planche en bois pour avoir un aperçu de où placer chaque élément de notre projet. Ensuite on a fait des trou pour y faire passer les fils et composantes qu’on va placer à l’intérieur de la boîte. Voici le résultat:

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/planche_base.jpeg" alt="base du projet" 
height="300">

- ##### Découpage boîte finale

On avait prévu d'utiliser un certain type de capteurs de distance pour notre projet, les capteurs TCRT5000, sauf qu'on en avait que 2 sur 4 du coup on a dû trouver une solution. J’ai alors soudé le capteur optique du TCRT5000 dans un capteur de proximité à infrarouges FC 51, parce que nous avions besoin de la forme rectangulaire du capteur optique du TCRT5000. Une fois la soudure complétée, j'ai vérifié que le capteur fonctionnait bien. On peut voir ici un capteur optique du TCRT5000 ainsi que le résultat final de la soudure:

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/tcrt5000.jpg" alt="capteur optique du TCRT5000" 
height="300">
<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/capteurs_distance.jpeg" alt="soudure des capteurs de distance" height="300">

- ##### 2 écrans sur une carte Arduino Uno et unification du code

Le reste de la séance j’ai cherché comment pouvoir connecter deux écran lcd sur une seule carte grâce au module i2c. Il a fallu souder dans l’un des deux modules une encoche (ici la A0) afin de lui changer d’adresse. Par défaut l’adresse d’un écran avec le module i2c est 0x27 mais en soudant l’adresse de la deuxième carte a changé en 0x26. On peut voir la soudure: 

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/ecrans2_A0.jpeg" alt="écrans soudé sur A0" 
height="300">  

Bien évidemment j’ai récupéré l’adresse de chaque carte grâce au scanneur i2c dont le code est [ici](https://github.com/villeautonome/Ville-Connectee/tree/main/rapport%20séances/Francesco/codes/I2C_scanner) et voici le résultat du scanner:

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/I2Cscanner.png" alt="résultat scanner I2C" 
height="150"> 

Une fois l’opération terminée j’ai effectué le montage est j’ai vérifié si on avait bien deux affichages différents dans les cartes grâce à un [code test](https://github.com/villeautonome/Ville-Connectee/tree/main/rapport%20séances/Francesco/codes/test_2_ecrans). Le résulta donne ça: 

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/test_2ecrans.png" alt="test 2 écrans soudé" 
height="300">  

J’ai donc unifié le code que j’avais écrit avec celui de mon binôme puisque maintenant on peut utilisé une seule carte arduino uno étant donné que notre problème principal était le fait qu’on n’arrivait pas à utiliser deux écrans relié à une même carte arduino. Il y a le code [ici]() et les deux écrans avec ce code ici: 

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/resultat_2ecrans.jpeg" alt="vérification 2 écrans" 
height="300">  
