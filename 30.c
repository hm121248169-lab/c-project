#include<stdio.h>

void ni(int a[],int n){
    int  *start=a;
    int *end=a+n-1;
    while(start<end){
        int temp=*start;
        *start=*end;
        *end=temp;
        start++;
        end--;
    }
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0){
        int a[20];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        ni(a,n);
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
}