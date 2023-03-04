# Huitième séance du 3 Mars 2023

Durant ma huitième et dernière séance j'ai travaillé sur une version améliorée de notre projet.
Au départ on avait décidé de garder le projet qu'on avait réalisé et en faire un deuxième à côté mais amélioré.

- #### Travail sur un la version 2 du projet

Je suis allé au fablab pour souder un nouvel écran, souder les led avec les résistances pour les nouveaux lampadaires et réaliser une nappe pour que tous les fils soient bien reliés entre-eux. De plus j’ai découpé une nouvelle boîte en bois même s’il y a eu quelques soucis à la faire à cause des dimensions et du manque de planches en bois. Au final le tout a été réalisé:

Malheureusement cette deuxième version ne peut pas aboutir car on a eu un manque de temps...

- #### Travail sur l'entrée du parking et matrice led

Ensuite j’ai récupéré une matrice led 8x8 qui sera placée à l’entrée du parking et qui affichera tout simplement le nombre de places disponibles. Dans le cas où il n’y aurait aucune place disponible toute la matrice led se mettrait à clignoter. Pour cela j’ai alors dû utiliser ce site pour pouvoir coder chaque led de la matrice qui sera indiqué en binaire pour pouvoir après réécrire chaque ligne en hexadécimal pour mon code. Dans le GitHub il y a le code pour la matrice simple ici et la versione unifié que j’ai fait en intégrant aussi le parking ici. Voici le résultat que cela donne:

De plus j’ai réaliser un fichier svg pour réaliser une petite boîte qui va contenir la matrice led et qu’on va placer à l’entrée du parking. Voici le fichier ainsi que le résultat final avec un trou dans la boîte pour voir la matrice:

- #### Travail sur détecteur de poussière

Grâce à mon professeur j’ai compris un peu mieux comment utiliser le module de capteur de poussière DSM501A pm2,5. On a pu faire ensemble le montage et tester ce capteur grâce à un code trouvé en ligne. Le détecteur renvoie le nombre de particules pour 1/100 de pied cube (environ 0,03 mètres cubes). Voici la photo du montage:
J’ai réussi à afficher les valeur sur l’écran lcd que j’avais soudé préalablement du coup j’ai pu unifier cette composante avec le code de la station météo et des lampadaires, le code est ici.






- #### Travail sur un côté du projet

Je suis allé au fablab pour uiliser la perceuse laser afin de faire 2 trous sur l'un des côtés de notre boîte afin de pouvoir y faire passer les cables d'alimentation pour les cartes Arduino. Pour cela j'ai du créer un fichier avec Inkscape avec un rectangle de 1cm de hauteur et 1,5cm de largueur, ce rectangle correspond au trou pour faire passer le cable. J'ai alors positionné ma planche en bois dans la machine, positionné le laser aux 2 endroits où je voulais découper et une fois la machine lancée les deux trous ont été découpés.

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/planche_cote.jpeg" alt="trous sur coté de boite" 
height="300">

- #### Achèvement de la station météo

Une fois que le professeur m'a procuré un morceau d'herbe synthétique pour les maquettes (différente su gazon) j'ai découpé avec les ciseaux un carré dans un côté pour laissé la place à notre capteur de luminosité et ensuite j'ai utiliser la perceuse pour faire un trou afin d'y faire passer les fils qui vont relier l'écran de la station météo.  

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/herbe_maquette.jpeg" alt="herbe" 
height="300">

Après tout ce travail j'ai alors collé sur la planche en bois ce bout d'herbe avec de la colle super forte et relié tous les fils afin de tester le tout. On peut voir le résultat final :

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/statio_meteo_fin.jpeg" alt="station météo final" height="300">

- #### Finalisation des lampadaires et montage final

Tous les composants de notre projet ont été branchés sur les deux plaques d'essai ou collés sur la planche en bois. J'ai dû soûder une première fois 2 capteurs de distance étant donné qu'ils s'étaient désouder et ensuite aussi une deuxième fois après avoir collé le capteur sur la planche en bois, cette deuxième fois a été un peu plus compliquée étant donné qu'il y avait tous les fils et qu'il fallait tenir la planche en bois un peu surélevée. On peut voir ici l'intérieur de notre boite avec tous les fils, les plaquettes ainsi que les cartes arduino:

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/cablages.jpeg" alt="intérieur boite" 
height="300">

Ensuite avant de coller les lampadaires avec la super colle on les a testé, on s'est aperçu que 2 lampadires étaient défaillants. On peut voir un exemple ici:
<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/lampadaire_casse.jpeg" alt="lampadaire défaillant" 
height="300"> La solution a été relativement simple, pour un lampadire il y avait un problème de cablâge et pour l'autre il a fallu repositionner la résistance du lampadire dans la plaquette.

On a alors collé les deux cartes Arduino dans notre boîte avec du scotch double face (biadhésif) et de la super colle. Je vous laisse ici une vue latérale de notre projet:
<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/vue_laterale.jpeg" alt="vue latérale" 
height="300">

On a donc fermé la boîte, collé des parties de celle-ci parce que les encoches qui permettent la fermeture ne tenaient pas, branché les deux cartes et testé si l'ensemble du projet fonctionnait.

<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/lampadaire_allume.jpeg" alt="projet allumé" 
height="300">
<img src="https://github.com/villeautonome/Ville-Connectee/blob/main/rapport%20séances/Francesco/images/lampadaire_eteint.jpeg" alt="ensemble du projet" 
height="300">
