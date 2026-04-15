#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;
    

       
    int getDaysInMonth(int m, int y) {
        if (m == 2) {
            return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) ? 29 : 28;
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        } else {
            return 31;
        }
    }

    
public:
    Date(int d = 1, int m = 1, int y = 2008) : day(d), month(m), year(y) {}
    
    void assign(int d, int m, int y) {
        year = y;
        
        if (m > 12) {
            m = m % 12;
            if (m == 0) m = 12;
        }
        month = m;
        
        int daysInMonth = getDaysInMonth(month, year);
        if (d > daysInMonth) {
            d = d % daysInMonth;
            if (d == 0) d = daysInMonth;
        }
        day = d;
    }
    
    void display() {
        cout << day << "/" << month << "/" << year << endl;
    }
    
    bool Leap_year() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    
    void increment(int n) {
        day += n;
        
        while (day > getDaysInMonth(month, year)) {
            day -= getDaysInMonth(month, year);
            month++;
            
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
};

int main()
{   
    Date date1, date2(1,5,2016), date3;
    int n, day, month, year;
    
    cin >> day >> month >> year;
    date3.assign(day, month, year);
    cin >> n;
    
    date1.display();
    date2.display();
    date3.display();
    
    date3.increment(n);
    date3.display();
    
    return 0; 
}