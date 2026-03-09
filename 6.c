#include<stdio.h>
int sum(int n){
    int s=0;
    while(n>0){
        s+=n%10;
        n/=10;
    }
    return s;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int x=sum(n);
        printf("%d",x);
        printf("\n");
    }
    return 0;
}