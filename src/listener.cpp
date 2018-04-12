
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <string>
#include <sstream>
#include "homework1/messaggio.h"

using namespace std;



static string comand;



void chatterCallbackH(const std_msgs::String::ConstPtr& msg)
{
  
	comand = msg->data.c_str();
	
}


void chatterCallbackT (const homework1::messaggio& msg){

	if(comand.compare("a") == 0)
    	ROS_INFO("Messaggio: [%s, %s, %s]", msg.nome.c_str(), msg.eta.c_str(), msg.corso.c_str());
	else if(comand.compare("n") == 0)
    	ROS_INFO("Messaggio: [%s]", msg.nome.c_str());
  	else if(comand.compare("e") == 0)
    	ROS_INFO("Messaggio: [%s]", msg.eta.c_str());
  	else if(comand.compare("c") == 0)
		ROS_INFO("Messaggio: [%s]", msg.corso.c_str());
	else if(comand.compare("q") == 0){
		ros::shutdown();
		exit(0);
	}

}

int main(int argc, char **argv)
{

	ros::init(argc, argv, "listener");

	ros::NodeHandle nListener;

	ros::Subscriber subL = nListener.subscribe("chatterHandler", 1000, chatterCallbackH);
	ros::Subscriber subT = nListener.subscribe("chatterTalker", 1000, chatterCallbackT);
  

	ros::spin();

  return 0;
}

