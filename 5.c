#include<stdio.h>
double average(int n,int m){
    return (n+m)/2.0;
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    double x=average(a,b);
    printf("%.1lf",x);
    return 0;
}