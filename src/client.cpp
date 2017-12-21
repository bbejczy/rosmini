#include "ros/ros.h"
#include "ros_wms/AddTwoInts.h"
#include <cstdlib>


int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_client");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<ros_wms::AddTwoInts>("add_two_ints");
  ros_wms::AddTwoInts srv;
  int a = 1, b = 2;
  srv.request.itemNumber = a;
  if (client.call(srv))
  {
  //  ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }
//
  return 0;
}
