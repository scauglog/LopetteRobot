#!/bin/sh

if [[ "$1" =~ /dev/ttyUSB. ]]
then
    avr-objcopy -O binary bin/LopetteRobot bin/LopetteRobot.bin
    avrdude -p m8 -c arduino -P $1 -b 19200  -U flash:w:bin/LopetteRobot.bin
else
    echo "./transfer.sh /dev/ttyUSB*"
fi
