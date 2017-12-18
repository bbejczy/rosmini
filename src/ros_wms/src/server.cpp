#include <iostream>
#include <thread>
#include <algorithm>
#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/simple_client_goal_state.h>
#include <geometry_msgs/PointStamped.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <sstream>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

using namespace std;

struct PERSON {   // Declare PERSON struct type
    int age;   // Declare member types
    long ss;
    float weight;
    char name[25];
} family_member;   // Define object of type PERSON
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "busroute");
    struct PERSON sister;   // C style structure declaration
    PERSON brother;   // C++ style structure declaration
    sister.age = 13;   // assign values to members
    brother.age = 7;
    cout << "sister.age = " << sister.age << '\n';
    cout << "brother.age = " << brother.age << '\n';



    std::cerr << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
    << '\n' << '\n'<< '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
    << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n'
                << "***********************************************"
                << '\n' <<
                  "Welcome to the B2-12 warehouse management system." <<
                  '\n' <<
                  "***********************************************" <<
                  '\n' << '\n';



    ros::spin(); //Spinns the ros packages
    return 0;
}
