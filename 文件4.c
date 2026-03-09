#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    char line[1001];
    int lineNumber = 1;
    fp = fopen("test.txt","r");
    if(fp==NULL){
        printf("Error opening file\n");
        exit(0);
    }
    while(fgets(line,1001,fp)!=NULL){
        if(strstr(line,"for")!=NULL){
            printf("The row including 'for' is : %d\n", lineNumber);
            printf("%s",line);
        }
        lineNumber++;
    }
    fclose(fp);
    return 0;
}