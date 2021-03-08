# ROS Racecar for Traxxas RC Car

## Preparation


```
cd catkin_ws/src
git clone https://github.com/ccny-ros-pkg/scan_tools.git
sudo apt-get install ros-melodic-csm -y
```

```
  sudo gedit /opt/ros/melodic/share/cv_bridge/cmake/cv_bridgeConfig.cmake 
  set(_include_dirs "include;/usr/include;/usr/include/opencv")
  set(_include_dirs "include;/usr/include;/usr/include/opencv4")
```

```
cd catkin_ws/src

git clone https://github.com/Road-Balance/racecar.git

sudo apt-get install qt4-default
sudo apt-get install ros-melodic-cv-bridge
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
  port: /dev/ttyACM0
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
```

**launch!!**
> roslaunch racecar teleop.launch

## Run

#TODO : etc udev rules.d

```
# terminal 1
cd /dev 
sudo chmod 777 /dev/vesc
sudo chmod 777 /dev/ttyACM0
sudo chmod 777 /dev/ttyACM1
sudo chmod 777 /dev/rplidar
cd ~/
cd ~/catkin_ws
sds
roslaunch racecar teleop.launch

# terminal 2
source ~/.bashrc_bridge
export ROS_MASTER_URI=http://localhost:11311/
ros2 run ros1_bridge dynamic_bridge

# terminal 3
roseloq
ros2 run webrtc_bot web_sub_joy_pub

#terminal 4
roseloq
ros2 run webrtc_bot regular_joy_pub


# Option  / check success && camera on
cd /home/swimming/dev_ws/src/traxxas-teamGRIT/webrtc_bot/launch
ros2 launch 
ros2 launch web_sub_joy.launch.py
```

gmapping
> [caution] check ROS_MASTER_URI
```
# run this after ssh 
roslaunch racecar gmapping.launch

# local laptop
roslaunch racecar gmapping_rviz.launch 
rosrun joy joy_node joy:=/vesc/joy _autorepeat_rate:=30
rosbag record -a
rosbag play <your-rosbag>
```
