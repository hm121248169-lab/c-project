#include<stdio.h>
#include<string.h>
struct Student
{
char id[10];
char name[20];
float marks;
};
int main(){
    int n;
    int max,min;
    scanf("%d",&n);
    struct Student s[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%s %s %f",s[i].id,s[i].name,&s[i].marks);

    }
    max=min=s[0].marks;
    for(i=1;i<n;i++){
        if(s[i].marks>max)
            max=s[i].marks;
        if(s[i].marks<min)
            min=s[i].marks;
    }
    for(i=0;i<n;i++){
        if(s[i].marks==max)
            printf("%s  ",s[i].name);
        
    }
    for(i=0;i<n;i++){
        if(s[i].marks==min)
            printf("%s  ",s[i].name);
    }
    return 0;
}