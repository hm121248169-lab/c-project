#include<stdio.h>

int digui(int n){
    if(n==1){
        return 18;
    }else{
        return digui(n-1)-2;
    }
    
    
}

int main(){
    int n;
    
    while(scanf("%d",&n)!=EOF && n!=0){
        int age = digui(n);
        printf("%d\n",age);
    }
    
    return 0;
}