#include<stdio.h>
int zhan(int a,int b){
    int num1=a,num2=b;
    while(b>0){
        int temp=b;
        b=a%b;
        a=temp;
    
    }
   
    return a;
}
int main(){
    int m,n;
    int result;
    scanf("%d%d",&m,&n);
    result=zhan(m,n);
    printf("%d %d",result,(m*n)/result);
    return 0;
}
