#include<stdio.h>

int tao(int n){
    if(n==1) return 1;
    else return 2*(tao(n-1)+1);
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF && n!=0){
        int a=tao(n);
        printf("%d\n",a);
        
    }
    return 0;
        
}