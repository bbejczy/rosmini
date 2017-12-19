#include <iostream>
#include <ros/ros.h>


using namespace std;

void printItem( struct Items Item );

struct Items {
    int   itemNumber;
    char  itemName[50];
    float x_coordinate;
    float y_coordinate;
    int shelf;
    int rack;
};

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "busroute");
    struct Items Item1;        // Declare Item1 of type Item
    struct Items Item2;        // Declare Item2 of type Item

      // Item 1 specification
      Item1.itemNumber = 649;
      strcpy( Item1.itemName, "Chand Miyan");
      Item1.x_coordinate = 159.643924;
      Item1.y_coordinate = 159.643924;
      Item1.shelf = 1;
      Item1.rack = 1;

    // Print Item1 info
    printItem( Item1 );

    ros::spin(); //Spinns the ros packages
    return 0;
}
void printItem( struct Items Item ) {
  std::cerr << "itemNumber: " << Item.itemNumber << '\n';
  std::cerr << "itemName: " << Item.itemName << '\n';
  std::cerr << "x-coordinate: " << Item.x_coordinate << '\n';
  std::cerr << "y-coordinate" << Item.y_coordinate << '\n';
  std::cerr << "shelf: " << Item.shelf << '\n';
  std::cerr << "rack: " << Item.rack << '\n';
}
