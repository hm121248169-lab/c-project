#include<stdio.h>
#include<string.h>
#include<math.h>
struct Student{
    int id [5];
    char name [10];
    int score;
    char department[100];

};

int main(){
    int n;  
    struct Student students[101];
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d %s %d %s", &students[i].id, students[i].name, &students[i].score, students[i].department);
    }
    
    
    int total = 0;
    for(i=0;i<n;i++){
        total = total+students[i].score;
    }
    double average = (double)total/n;
    int count = 0;
    for(i=0;i<n;i++){
        if(students[i].score>average){
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
    
    