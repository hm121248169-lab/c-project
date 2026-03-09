#include<stdio.h>
#include<string.h>
struct Student{
    char id[20];
    int age;
    float score;
    
};
int main(){
    int n;
    int find=0;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        struct Student s[n];
        scanf("%s %d %f",s[i].id,&s[i].age,&s[i].score);
        if(s[i].score>80){
            find++;
        }
    }
    printf("%d",find);
    return 0;
}