#include<stdio.h>

int zero(int a,int b){
    int s=a*b+a+b;
    return s;
}

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int result=zero(a,b);
    printf("%d\n",result);
    return 0;
}