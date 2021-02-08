# ROS Racecar for Traxxis RC Car

## Preparation

```
cd catkin_ws/src

git clone https://github.com/Road-Balance/racecar.git

sudo apt-get install ros-melodic-serial

catkin_make
source devel/setup.bash
```

```
# check ACM
cd /dev
ls | grep ttyACM
> ttyACM?
```

* set proper port number through `vesc.yaml`
```yaml
vesc_driver:
  port: /dev/ttyACM1
  duty_cycle_min: 0.0
  duty_cycle_max: 0.0
  current_min: 0.0
  current_max: 20.0
  brake_min: -20000.0
  brake_max: 200000.0
  speed_min: -3250
  speed_max: 3250
  position_min: 0.0
  position_max: 0.0
  servo_min: 0.15
  servo_max: 0.85
```

give permission
``` 
sudo chmod 777 ttyACM0
# or
sudo chmod 777 ttyACM1

roslaunch racecar teleop.launch
```

