#!/bin/sh
sudo pacman -S udiskie udisks2
sudo groupadd storage
sudo groupadd power
sudo groupadd users
sudo cp 50-udiskie.rules /etc/polkit-1/rules.d/
sudo cp 10-rules.rules /etc/polkit-1/rules.d/
sudo chmod 644 50-udiskie.rules
sudo chmod 644 10-rules.rules
echo "Done! Please restart your computer"