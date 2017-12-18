#include <iostream>
#include <ros/ros.h>


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




    ros::spin(); //Spinns the ros packages
    return 0;
}
