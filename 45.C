#include<stdio.h>
#include<string.h>
struct staff{
    char id[10];
    char name[20];
    int age;
};

int main(){
    int n;
    int find1=0;
    int find2=0;
    int find3=0;
    scanf("%d",&n);
    struct staff s[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%s %s %d",s[i].id,s[i].name,&s[i].age);
        if(s[i].age<=10){
            find1++;
        }else if(s[i].age>10&&s[i].age<=20){
            find2++;
        }else if(s[i].age>20){
            find3++;

        }
    }
    printf("%d,%d,%d",find1,find2,find3);
    return 0;
}