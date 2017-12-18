#include <iostream>
#include <ros/ros.h>


using namespace std;

void printBook( struct Books book );

struct Books {
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
    struct Books Book1;        // Declare Book1 of type Book
    struct Books Book2;        // Declare Book2 of type Book

    // book 1 specification
    Book1.itemNumber = 649;
    strcpy( Book1.itemName, "Chand Miyan");
    Book1.x_coordinate = 159.643924;
    Book1.y_coordinate = 159.643924;
    Book1.shelf = 1;
    Book1.rack = 1;


    // Print Book1 info
    printBook( Book1 );

    ros::spin(); //Spinns the ros packages
    return 0;
}
void printBook( struct Books book ) {
  std::cerr << "itemNumber: " << book.itemNumber << '\n';
  std::cerr << "itemName: " << book.itemName << '\n';
  std::cerr << "x-coordinate: " << book.x_coordinate << '\n';
  std::cerr << "y-coordinate" << book.y_coordinate << '\n';
  std::cerr << "shelf: " << book.shelf << '\n';
  std::cerr << "rack: " << book.rack << '\n';
}
