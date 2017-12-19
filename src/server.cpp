#include <iostream>
#include <ros/ros.h>
#include "rosmini/AddTwoInts.h"
#include <cstdlib>

using namespace std;

void printItem( struct Items Item );

struct Items {
    int   itemNumber;
    char  itemName[50];
    float x_coordinate;
    float y_coordinate;
    int shelf;
    int row;
    int column;
};

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "busroute");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("add_two_ints", add); //////////////////////////////


    struct Items Item[6];        // Declare Item1 of type Item
    //struct Items Item        // Declare Item2 of type Item

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("add_two_ints", add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();

  return 0;
}
// #include <tuple>
// #include <iostream>
// #include <string>
// #include <stdexcept>
// #include <ros/ros.h>
//
// std::tuple<double, char, std::string> get_student(int id)
// {
//     if (id == 0) return std::make_tuple(3.8, 'A', "Lisa Simpson");
//     if (id == 1) return std::make_tuple(2.9, 'C', "Milhouse Van Houten");
//     if (id == 2) return std::make_tuple(1.7, 'D', "Ralph Wiggum");
//     throw std::invalid_argument("id");
// }
//
// int main()
// {
//   ROS_ERROR("ROS_ERRORRRRRRRRRRRR");
//     auto student0 = get_student(0);
//     std::cerr << "ID: 0, "
//               << "GPA: " << std::get<0>(student0) << ", "
//               << "grade: " << std::get<1>(student0) << ", "
//               << "name: " << std::get<2>(student0) << '\n';
//
//     double gpa1;
//     char grade1;
//     std::string name1;
//     std::tie(gpa1, grade1, name1) = get_student(1);
//     std::cerr << "ID: 1, "
//               << "GPA: " << gpa1 << ", "
//               << "grade: " << grade1 << ", "
//               << "name: " << name1 << '\n';
// }
