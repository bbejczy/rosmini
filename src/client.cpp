1 #include "ros/ros.h"
2 #include "beginner_tutorials/AddTwoInts.h"
3 #include <cstdlib>
4
5 int main(int argc, char **argv)
6 {
7   ros::init(argc, argv, "add_two_ints_client");
8   if (argc != 3)
9   {
10     ROS_INFO("usage: add_two_ints_client X Y");
11     return 1;
12   }
13
14   ros::NodeHandle n;
15   ros::ServiceClient client = n.serviceClient<beginner_tutorials::AddTwoInts>("add_two_ints");
16   beginner_tutorials::AddTwoInts srv;
17   srv.request.a = atoll(argv[1]);
18   srv.request.b = atoll(argv[2]);
19   if (client.call(srv))
20   {
21     ROS_INFO("Sum: %ld", (long int)srv.response.sum);
22   }
23   else
24   {
25     ROS_ERROR("Failed to call service add_two_ints");
26     return 1;
27   }
28
29   return 0;
30 }
