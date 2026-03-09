#include<stdio.h>

int change(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int main(){
    int x,m,n;
    scanf("%d",&x);
    while(x--){
        scanf("%d %d",&m,&n);
        change(&m,&n);
        printf("%d %d\n",m,n);
    }
    return 0;
}