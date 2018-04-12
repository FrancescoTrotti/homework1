
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream> 
#include <sstream>



#include <termios.h>


using namespace std;

int main(int argc, char **argv)
{

	ros::init(argc, argv, "handler");

	ros::NodeHandle nHandler;

	ros::Publisher chatter_handler = nHandler.advertise<std_msgs::String>("chatterHandler", 1000);
	
	
	std_msgs::String msg;

    string ss;

	while (ros::ok())
	{
		string c;
	
		cout << "Digita uno dei caratteri per visualizzare le eventuali infomazioni\n a - Stampa tutto il messaggio\n n - Stampa il nome\n e - Stampa l'eta'\n c - Stampa il corso di studi\n q - Esci" << endl;
	
		cin >> c;
	
		if(c == "a" || c == "e" || c == "n" || c == "c")
    	{
   
			msg.data = c;
    		ROS_INFO("%s", msg.data.c_str());
			fflush(stdout);
    		chatter_handler.publish(msg);

		}else if (c == "q"){

			msg.data = c;
			ROS_INFO("%s", msg.data.c_str());
			fflush(stdout);
        	chatter_handler.publish(msg);
			ros::shutdown();
			exit(0);

		}
	
	}

  return 0;
}

