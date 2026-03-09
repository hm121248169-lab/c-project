#include<stdio.h>
#include<string.h>

struct Student{
    char id[20];
    char name[20];
    float score;
};
int main(){
    struct Student stu[100];
    int i;
    for(i=0;i<8;i++){
        scanf("%s %s %f",stu[i].id,stu[i].name,&stu[i].score);
    }
    int max=0;
    for(i=1;i<8;i++){
        if(stu[i].score>stu[max].score){
            max=i;
        }
    }
    printf("%s %s %.0f\n",stu[max].id,stu[max].name,stu[max].score);
    return 0;
}
