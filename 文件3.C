#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    char ch;
    int count = 0;
    fp = fopen("chap14_file1.txt", "r");
    if(fp == NULL){
        printf("Error opening file\n");
        exit(0);
    }

    while((ch = fgetc(fp)) != EOF){
            
            count++;
        
    }
    fclose(fp);
    
    printf("%d\n", count);
    return 0;
}