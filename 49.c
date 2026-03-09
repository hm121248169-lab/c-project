#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    double num;
    int count = 0;
    fp = fopen("chap12_exercise2.dat", "w");
    while(1){
        scanf("%lf", &num);
        if(num==-1){
            break;
        }
        if(count>0){
            fprintf(fp, "  ");
        }
        fprintf(fp, "%lf", num);
        count++;
    }
    fclose(fp);
    return 0;
}