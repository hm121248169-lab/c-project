#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    char str[101];
    fp = fopen("test.txt","r");
    if(fp==NULL){
        printf("Error opening file\n");
        exit(0);

    }
    if(fgets(str,101,fp)!=NULL){
        printf("%s",str);
    }
    fclose(fp);
    return 0;
}