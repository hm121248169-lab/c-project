#include<stdio.h>
int fei(int n){
    int a[100];
    a[0]=1,a[1]=1;
    for(int i=2;i<=n;i++)
        a[i]=a[i-1]+a[i-2];
    return a[n];

}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",fei(n-1));
    return 0;
}
