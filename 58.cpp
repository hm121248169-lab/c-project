#include<bits/stdc++.h>
using namespace std;

class current_date{
private:
    int day;
    int month;
    int year;
    
    bool isLeapYear(int y){
        if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)){
            return true;
        }
        return false;
    }
    
    int daysInMonth(int m, int y){
        switch(m){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                return isLeapYear(y) ? 29 : 28;
            default:
                return 30;
        }
    }

public:
    current_date(int dayVal, int monthVal, int yearVal):day(dayVal),month(monthVal),year(yearVal){}
    //调用时机：只能在创建对象时调用一次，用途：初始化对象
    void assign_data(int dayVal, int monthVal, int yearVal){
        day = dayVal;
        month = monthVal;
        year = yearVal;
    }
    
    void display_data(){
        cout<<month<<"/"<<day<<"/"<<year<<endl;
    }//调用时机：对象创建后，可以多次调用用途：修改已存在对象的值，上下不冲突
    
    void increment_date(){
        day++;
        if(day > daysInMonth(month, year)){
            day = 1;
            month++;
            if(month > 12){
                month = 1;
                year++;
            }
        }
    }
};

int main(){
    int i, day,month,year;
    current_date mydate(10,1,2013);
    mydate.display_data();
    cin>>day>>month>>year;
    mydate.assign_data(day,month,year);

    for(i=1;i<=10;i++){
        mydate.increment_date(); 
    }
    mydate.display_data();

    return 0;
}