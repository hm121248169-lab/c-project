#include <iostream>
#include <string>
using namespace std;

class worker {
protected:
    string workerID;
    string wName;
public:
    worker(string IDValue, string nameValue) : workerID(IDValue), wName(nameValue) {}
};

class teacher : virtual public worker {
protected:
    string title;
    string speciality;
public:
    teacher(string IDValue, string nameValue, string titleValue, string specialValue)
        : worker(IDValue, nameValue), title(titleValue), speciality(specialValue) {}
    
    void display() {
        cout << "I am a teacher, my name is " << wName 
             << ", title is " << title 
             << ", speciality is " << speciality << "." << endl;
    }
};

class staff : virtual public worker {
protected:
    string position;
public:
    staff(string IDValue, string nameValue, string positionValue)
        : worker(IDValue, nameValue), position(positionValue) {}
    
    void display() {
        cout << "I am a staff, my name is " << wName 
             << ", position is " << position << "." << endl;
    }
};

class leader : public teacher, public staff {
private:
    int workNumber;
public:
    leader(string IDValue, string nameValue, string titleValue, string specialValue, 
           string positionValue, int num)
        : worker(IDValue, nameValue), 
          teacher(IDValue, nameValue, titleValue, specialValue),
          staff(IDValue, nameValue, positionValue),
          workNumber(num) {}
    
    void display() {
        cout << "I am a leader, my name is " << wName 
             << ", title is " << title 
             << ", speciality is " << speciality 
             << ", my position is " << position 
             << " and there are " << workNumber 
             << " worker in my department." << endl;
    }
};

int main()
{
    string num,name,title,special,position;
    int workNum;  
    
    cin>>num>>name>>title>>special;
    teacher t1(num,name,title,special);  
    
    cin>>num>>name>>position;
    staff s1(num,name,position);

    cin>>num>>name>>title>>special>>position>>workNum;
    leader l1(num,name,title,special,position,workNum);

    t1.display();
    s1.display();
    l1.display();
    return 0;
}