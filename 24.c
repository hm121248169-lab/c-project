#include<stdio.h>

int high(int *p){
    while(*p>=10){
        *p/=10;
    }
    return *p;
}

int main(){
    int n;
    while(scanf("%d",&n)==1){
        high(&n);
        printf("%d\n",n);
    
    }
    return 0;
}