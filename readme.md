Projet SE
création d'un pilote et un firmware pour Lopette

Pour compiler le projet :
$ cd build
{
$ cmake .. -DMODE=ARDUINO # pour compiler pour arduino
ou
$ cmake .. -DMODE=PC      # pour compiler pour son ordi
ou
$ cmake ..                # pour utiliser le mode de compilation
  			  # précédemment sélectionner
}
$ make
$ ./bin/LopetteRobot
