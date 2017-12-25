#include "ros/ros.h"
#include "ros_wms/serv.h"
#include <iostream>
#include <cstdlib>
#include <string>

  ros_wms::serv srv;

  struct products {
    int itemNumber;
    std::string itemName;
    float x_coordinate;
    float y_coordinate;
    int shelf;
    int row;
    int column;
  };

  struct products *product;

bool add(ros_wms::serv::Request  &req,
         ros_wms::serv::Response &res)
{
    int n = req.itemNumber;

    res.itemName = product[n].itemName;
    res.itemNumber = product[n].itemNumber;
    res.x_coordinate = product[n].x_coordinate;
    res.y_coordinate = product[n].y_coordinate;
    res.row = product[n].row;
    res.column = product[n].column;
    res.shelf = product[n].shelf;

  return true;
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "Warehouse_management_system_server");

  ros::NodeHandle n;
  int arrayLength = 5;
  //Hardcoded database
  product = new struct products[arrayLength];

  product[0].itemNumber = 1;
  product[0].itemName = "Shovel";
  product[0].x_coordinate = 88.52;
  product[0].y_coordinate = 23.87;
  product[0].row = 4;
  product[0].column = 1;
  product[0].shelf = 2;

  product[1].itemNumber = 2;
  product[1].itemName = "Aluminium ruler";
  product[1].x_coordinate = 42.52;
  product[1].y_coordinate = 03.17;
  product[1].row = 2;
  product[1].column = 3;
  product[1].shelf = 1;

  product[2].itemNumber = 3;
  product[2].itemName = "Screwdriver";
  product[2].x_coordinate = 33.22;
  product[2].y_coordinate = 17.97;
  product[2].row = 2;
  product[2].column = 3;
  product[2].shelf = 2;

  product[3].itemNumber = 4;
  product[3].itemName = "Utility knife";
  product[3].x_coordinate = 8.52;
  product[3].y_coordinate = 107.27;
  product[3].row = 4;
  product[3].column = 2;
  product[3].shelf = 1;

  product[4].itemNumber = 5;
  product[4].itemName = "Steel hammer";
  product[4].x_coordinate = 12.12;
  product[4].y_coordinate = 24.33;
  product[4].row = 5;
  product[4].column = 2;
  product[4].shelf = 3;

  ros::ServiceServer service = n.advertiseService("wms", add);
  ROS_INFO("The server is now active");
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
