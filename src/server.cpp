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

      // Item 1 specification
      Item[0].itemNumber = 649;
      strcpy( Item[0].itemName, "Chand Miyan");
      Item[0].x_coordinate = 159.643924;
      Item[0].y_coordinate = 159.643924;
      Item[0].shelf = 1;
      Item[0].row = 1;
      Item[0].column = 44;

    // Print Item1 info
    printItem( Item[0] );

    ros::spin(); //Spinns the ros packages
    return 0;
}
void printItem( struct Items Item ) {
  std::cerr << "itemNumber: " << Item.itemNumber << '\n';
  std::cerr << "itemName: " << Item.itemName << '\n';
  std::cerr << "x-coordinate: " << Item.x_coordinate << '\n';
  std::cerr << "y-coordinate" << Item.y_coordinate << '\n';
  std::cerr << "shelf: " << Item.shelf << '\n';
  std::cerr << "row: " << Item.row << '\n';
  std::cerr << "column: " << Item.column << '\n';
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
