#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int i;
    int sum=0;
    int a=1;
    for(i=1;i<=n;i++){
        if((i-1)%2 == 0){
            sum += a;  // 正号项
        }else{
            sum -= a;  // 负号项
        }
        a++;
    }
    printf("%d",sum);
    return 0;
}