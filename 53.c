#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *fp;
    char str[101];
    fp = fopen("test.txt", "r");
    if(fp==NULL){
        printf("Error opening file.\n");
        exit(0);
    }
    int n=1;
    while(fgets(str,101,fp)!=NULL){
        if(strstr(str,"love")){
            printf("The row including 'love' is : %d\n", n);
            printf("%s\n",str);
        }
        n++;
    }
    fclose(fp);

    return 0;
}