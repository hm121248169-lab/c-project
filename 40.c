#include<stdio.h>

struct Complex{
    float real;
    float imag;
};
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    int i;
    for(i=0;i<n;i++){
        struct Complex c1,c2,res;
        char op;
        scanf("(%f%fi)%c(%f%fi)",&c1.real,&c1.imag,&op,&c2.real,&c2.imag);
        getchar();
        if(op=='+'){
            res.real=c1.real+c2.real;
            res.imag=c1.imag+c2.imag;
        }
        else if(op=='-'){
            res.real=c1.real-c2.real;
            res.imag=c1.imag-c2.imag;
        }
        
    printf("%.2lf%+.2lfi\n",res.real,res.imag);
    }
    return 0;
}