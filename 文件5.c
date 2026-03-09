#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    char ch;
    int letterCount = 0;
    int digitCount = 0;
    
    fp = fopen("chap12_exercise1.dat","r");
    if(fp==NULL){
        printf("Error opening file\n");
        exit(0);
    }
    while((ch = fgetc(fp)) != EOF){
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){
            letterCount++;
        }
        else if(ch >= '0' && ch <= '9'){
            digitCount++;
        }
    }
    
    fclose(fp);
    
    printf("The number of the character is %d\n", letterCount);
    printf("The number of the number is %d\n", digitCount);
    
    return 0;
}