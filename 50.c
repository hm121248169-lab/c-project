#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    FILE *file1, *file2;
    char line[81];
    file1=fopen("text1.dat","r");
    file2=fopen("text2.dat","w");
    if(file1==NULL || file2==NULL){
        printf("Error opening file\n");
        exit(0);
    }
    while(fgets(line, sizeof(line), file1) != NULL){
        int len = strlen(line);
       
        int i;
        for(i=len-1; i>=0; i--){
            if((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')){
                fputc(line[i], file2);
            }
        }
        fputc('\n', file2);
    }

    fclose(file1);
    fclose(file2);
    return 0;

}