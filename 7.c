#include<stdio.h>
double j(double a,double b,double c){
    int i;
    double a1=1,b1=1,c1=1;
    for(i=1;i<=a;i++){
        a1=a1*i;
    }
    for(i=1;i<=b;i++){
        b1=b1*i;
    }
    for(i=1;i<=c;i++){
        c1=c1*i;
    }
    return a1/(b1+c1);
}
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%.4lf",j(a,b,c));
    return 0;
}