#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        long long a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        // 如果所需水量超过两个容器容量之和，则无法实现
        if(c > a + b){
            printf("NO\n");
            continue;
        }
        // 如果所需水量等于任何一个容器或两个容器容量之和，则可以实现
        if(c == a || c == b || c == a + b){
            printf("YES\n");
            continue;
        }
        // 计算最大公约数(GCD)
        long long num1=a,num2=b;
        while(num2!=0){
            long long temp=num1%num2;
            num1=num2;
            num2=temp;
        }
        // 根据贝祖等式，当且仅当c能被gcd(a,b)整除时才有解
        if(c%num1==0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        long long a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        // 如果所需水量超过两个容器容量之和，则无法实现
        if(c > a + b){
            printf("NO\n");
            continue;
        }
        // 如果所需水量等于任何一个容器或两个容器容量之和，则可以实现
        if(c == a || c == b || c == a + b){
            printf("YES\n");
            continue;
        }
        // 计算最大公约数(GCD)
        long long num1=a,num2=b;
        while(num2!=0){
            long long temp=num1%num2;
            num1=num2;
            num2=temp;
        }
        // 根据贝祖等式，当且仅当c能被gcd(a,b)整除时才有解
        if(c%num1==0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}