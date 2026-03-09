#include<stdio.h>
#include<string.h>
struct Student{
    char id[20];
    char name[20];
    float score;
    
};
int main(){
    int n;
    int count=0;
    double sum=0;
    scanf("%d",&n);
    struct Student s[n];
    int i;
    for(i=0;i<n;i++){
        
        scanf("%19s %s %f",s[i].id,s[i].name,&s[i].score);
        sum+=s[i].score;
        if(s[i].score<60){
            count++;
        }
    }
    printf("%.2f\n",sum/(double)n);
    printf("%d\n",count);
    return 0;
}
