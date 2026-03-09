#include<stdio.h>

struct date{
    int year;
    int month;
    int day;
};
struct Teacher{
    char id[20];
    char name[20];
    char title[20];
    float bascicsalary;
    float allowance;
    float subsidy;
    struct date birthday;
};

int main(){
    struct Teacher teacher[3];
    int i;
    for(i=0;i<3;i++){
        scanf("%s%s%s%f%f%f%d%d%d",
            teacher[i].id,
            teacher[i].name,
            teacher[i].title,
            &teacher[i].bascicsalary,
            &teacher[i].allowance,
            &teacher[i].subsidy,
            &teacher[i].birthday.year,
            &teacher[i].birthday.month,
            &teacher[i].birthday.day);
    }
    for(i=0;i<3;i++){
        float totalsalary=teacher[i].bascicsalary+teacher[i].allowance+teacher[i].subsidy;
    if(totalsalary>5000){
        printf("姓名:%s,出生日期:%d.%d.%d,工资:%.0f\n",
            
            teacher[i].name,
            teacher[i].birthday.year,
            teacher[i].birthday.month,
            teacher[i].birthday.day,
            totalsalary);
        }

    }
    return 0;
}