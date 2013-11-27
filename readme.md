Projet SE
création d'un pilote et un firmware pour Lopette

Pour compiler le projet :
$ cd build


$ cmake .. -DMODE=ARDUINO # pour compiler pour arduino

ou

$ cmake .. -DMODE=PC      # pour compiler pour son ordi

ou

$ cmake ..                # pour utiliser le mode de compilation précédemment sélectionner

$ make

$ ./bin/LopetteRobot
avr-objcopy -O binary bin/LopetteRobot bin/LopetteRobot.bin

avrdude -p m8 -c arduino -P /dev/ttyUSB -b 19200  -U flash:w:bin/LopetteRobot.bin
