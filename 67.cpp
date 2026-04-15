#include<bits/stdc++.h>
using namespace std;

class robot
{
public:
    robot(double x = 0, double y = 0) : x_coord(x), y_coord(y)
    {}

    void display_position() // Inspector function to display the robot's position
    {
        cout << "(" << x_coord << "," << y_coord << ")" << endl;
    }

    // 向左移动，x 坐标减少
    bool left(double distance){
        double new_x = x_coord - distance;
        if(new_x < 0 || new_x > 100 || y_coord < 0 || y_coord > 100){
            return false;
        }
        x_coord = new_x;
        return true;
    }

    // 向右移动，x 坐标增加
    bool right(double distance){
        double new_x = x_coord + distance;
        if(new_x < 0 || new_x > 100 || y_coord < 0 || y_coord > 100){
            return false;
        }
        x_coord = new_x;
        return true;
    }

    // 向前移动，y 坐标增加
    bool forward(double distance){
        double new_y = y_coord + distance;
        if(x_coord < 0 || x_coord > 100 || new_y < 0 || new_y > 100){
            return false;
        }
        y_coord = new_y;
        return true;
    }

    // 向后移动，y 坐标减少
    bool back(double distance){
        double new_y = y_coord - distance;
        if(x_coord < 0 || x_coord > 100 || new_y < 0 || new_y > 100){
            return false;
        }
        y_coord = new_y;
        return true;
    }

    // 移动到指定位置
    bool goto_position(double x, double y){
        if(x < 0 || x > 100 || y < 0 || y > 100){
            return false;
        }
        x_coord = x;
        y_coord = y;
        return true;
    }

    // 返回基地 (0,0)
    void return_to_base(){
        x_coord = 0;
        y_coord = 0;
    }

private:
    double x_coord;
    double y_coord;
};

int main()
{
    double  px, py;
    robot puppy(59.6, 28.1);      // Constructor sets the initial position.
    if (puppy.left(1.3))
        puppy.display_position();       // Move robot left 1.3 cms, New position is ( 58.3,28.1)
    else
        cout << "position error!\n";
    if (puppy.back(12.0))
        puppy.display_position();        // Move robot back 12.0 cms, New position is ( 58.3,16.1)
    else      
        cout << "position error!\n";
    if (puppy.right(60.0))
        puppy.display_position();     // Move robot right 60.0 cms, 58.3+60=118.3>100, output "position error!"
    else     
        cout << "position error!\n";
    puppy.return_to_base();       // Sets the position to (0,0)
    puppy.display_position();
    puppy.forward(3.5);             // Move robot forward 3.5 cms,  New position is ( 0, 3.5 )
    puppy.display_position();
    cin >> px >> py;
    if (puppy.goto_position(px, py))
        puppy.display_position();
    else      
        cout << "position error!\n";
    return 0;
}