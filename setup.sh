#!/bin/bash


sudo ./rplidar_ros/scripts/create_udev_rules.sh

# Copy the RACECAR udev rules to /etc/udev/rules.d
# The rules alias the Sparkfun 9DoF IMU as IMU and the 
# Electronic Speed Controller as VESC
sudo cp udev/10-racecar.rules /etc/udev/rules.d
# Reread the rules; You may need to physically replug
sudo udevadm control --reload-rules 
sudo udevadm trigger
echo 'RACECAR Rules installed'
