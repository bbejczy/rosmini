#include "ros/ros.h"
#include "ros_wms/serv.h"
#include <cstdlib>
#include <string>
#include <iostream>

int x;

void printResponse(){
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<ros_wms::serv>("wms");
  ros_wms::serv srv;

  srv.request.itemNumber = x -1;
  if (client.call(srv))
  {
  std::cout << "Item name: " <<  srv.response.itemName << '\n';
  std::cout << "Item number: " << srv.response.itemNumber << '\n';
  std::cout << "Item x-coordinate: " << srv.response.x_coordinate << '\n';
  std::cout << "Item y-coordinate: " << srv.response.y_coordinate << '\n';
  std::cout << "Location row: " << srv.response.row << '\n';
  std::cout << "Location column: " << srv.response.column << '\n';
  std::cout << "Location shelf: " << srv.response.shelf << '\n';
  }
  else
  {
    ROS_ERROR("Failed to call service warehouse management system");
  }
}

void printList(){
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<ros_wms::serv>("wms");
  ros_wms::serv srv;
  int count = 5;
  for (int i = 0; i < count; i++)
  {
    int a = i + 1;
    if (client.call(srv))

    {
      srv.request.itemNumber = i;
      std::cout << "Item number " << a << ": " << srv.response.itemName << '\n';
    }

  }
   std::cout << '\n' << '\n';
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Warehouse_management_system_client");

  //Defines y as an integer
  int y = 0;
  //opening message
      std::cout << "\033[2J\033[1;1H"; //Clears the terminal
      std::cout << "Welcome to the B2-12 Warehouse Management System Interface" << '\n';
      label:
      std::cout << "" << '\n' << '\n'
                << "Please select a product to recieve further information about." << '\n'
                << "Enter a number corresponding to the list below: " << '\n' << '\n';
                printList();


      //takes input as value x
      std::cin >> x;
      std::cout << '\n' << "You entered: " << x << '\n';

          switch(x)
          //switch matches the x to a case, 1 through 5 in this example and executes a statement which is cout for now
          {
          case 1:
          std::cout << "" << '\n';
          std::cout << "Fetching data for item one: Shovel";
          std::cout << "" << '\n';
          std::cout << "" << '\n';
          y = 1;
          break;
          case 2:
          std::cout << "" << '\n';
          std::cout << "Fetching data for item two: Aluminum ruler";
          std::cout << "" << '\n';
          std::cout << "" << '\n';
          y = 1;
          break;
          case 3:
          std::cout << "" << '\n';
          std::cout << "Fetching data for item three: Screwdriver";
          std::cout << "" << '\n';
          std::cout << "" << '\n';
          y = 1;
          break;
          case 4:
          std::cout << "" << '\n';
          std::cout << "Fetching data for item four: Utility knife";
          std::cout << "" << '\n';
          std::cout << "" << '\n';
          y = 1;
          break;
          case 5:
          std::cout << "" << '\n';
          std::cout << "Fetching data for item five: Steel hammer";
          std::cout << "" << '\n';
          std::cout << "" << '\n';
          y = 1;
          break;
          default:
          std::cout << "" << '\n';
          std::cout << "***Invalid input***" << '\n';
          std::cout << "" << '\n';
          break;
          }

          if (y == 1)
          printResponse();

          std::cout << "Do you want to continue retrieving data? (y/n)." << '\n';
          char ans;
          std::cin >> ans;
          if(ans == 'y')
            goto label;
          else

  return 0;
}
