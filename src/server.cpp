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
    int row;
    int column;
};

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "busroute");
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
