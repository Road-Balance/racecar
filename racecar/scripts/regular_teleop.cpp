// sub : sensor_msgs.msg.Joy /joy
// pub : ackermann_msgs/AckermannDriveStamped /low_level/ackermann_cmd_mux/input/teleop
//

#include <ros/ros.h>
#include <ackermann_msgs/AckermannDriveStamped.h>
#include <tf/transform_broadcaster.h>
#include <sensor_msgs/Joy.h>

class TinyBot
{
private:
    ros::NodeHandle m_nh;
    ros::Publisher m_pub;
    ros::Subscriber m_sub;

    std::string m_name;
    geometry_msgs::Twist m_cmd_vel;

public:
    TinyBot(const std::string &name_in = "my_tiny"): m_name(name_in) {
        ROS_INFO("Publisher and Subscriber initialized");
        m_pub = m_nh.advertise<ackermann_msgs::AckermannDriveStamped>("/low_level/ackermann_cmd_mux/input/teleop", 1);
        m_sub = m_nh.subscribe("/joy", 1, &TinyBot::subCallback, this);
    }
    void subCallback(const sensor_msgs::Joy &data){
		// data to ackenmann
        std::cout << "===== front lidar point val : " << data << " ====" << std::endl;
    }
};

int main(int argv, char** argc) {

    ros::init(argv, argc, "parking_node");
    TinyBot tinybot("gcamp_robo");
    ros::spin();

    return 0;
}
