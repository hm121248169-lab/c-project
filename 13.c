#include<stdio.h>

int xin(int n){
    int a[100];
    int i=0;
    while(n>1){
        int num=n%10;
        if(num%2==0){
            a[i]=num;
            i++;
            
        }
        n=n/10;
    }
    int j;
    for( j=0;j<i;j++){
        printf("%d",a[j]);
    }
    printf("\n");
    return 0;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        xin(n);
    }
    
    return 0;
}