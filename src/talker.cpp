
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "homework1/messaggio.h"


int main(int argc, char **argv)
{

	ros::init(argc, argv, "talker");

	ros::NodeHandle n;

	ros::Publisher chatter_pub = n.advertise<homework1::messaggio>("chatterTalker", 1000);

	ros::Rate loop_rate(1);

	while (ros::ok())
	{

		homework1::messaggio msg;

    	std::stringstream ss;
    	ss << "Francesco";
    	msg.nome = ss.str();

		std::stringstream ss1;
		ss1 << "22 anni";
		msg.eta = ss1.str();

    	std::stringstream ss2;
    	ss2 << "Informatica";
    	msg.corso = ss2.str();

		ROS_INFO("nome: %s, eta: %s, corso: %s", msg.nome.c_str(), msg.eta.c_str(), msg.corso.c_str());

    	chatter_pub.publish(msg);

    	ros::spinOnce();

    	loop_rate.sleep();

	}

  return 0;
}

