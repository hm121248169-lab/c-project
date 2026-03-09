#include<stdio.h>
#include<stdlib.h>

struct Student{
    int id;
    char name[21];
    int age;
};

int main(){
    FILE *fp;
    struct Student student[4];
    int i;
    for(i=0;i<4;i++){
        scanf("%d %s %d",&student[i].id,student[i].name,&student[i].age);
    }
    fp=fopen("student.txt","w");
    if(fp==NULL){
        printf("Error opening file\n");
        exit(0);
    }
    for(i=0;i<4;i++){
        fprintf(fp,"%d %s %d\n",student[i].id,student[i].name,student[i].age);
        if(i<3){
            fprintf(fp,"\n");
        }
    }
    fclose(fp);
    fp=fopen("student.txt","r");
    if(fp==NULL){
        printf("Error opening file\n");
        exit(0);
    }
    for(i=0;i<4;i++){
        fscanf(fp,"%d %s %d",&student[i].id,student[i].name,&student[i].age);
        printf("%d %s %d\n",student[i].id,student[i].name,student[i].age);
    }
    fclose(fp);
    return 0;
}