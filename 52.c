#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void change(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    
    int n;
    while(scanf("%d",&n)!=EOF){
        int c[n];
        int i;
        for(i=0;i<n;i++){
            scanf("%d",&c[i]);
        }

        int *a=&c[0],*b=&c[0];
        for(i=0;i<n;i++){
            if(c[i]>*a){
                a = &c[i];
            }
            if(c[i]<*b){
                b = &c[i];
            }
        }
        
        change(a,b);
        for(i=0;i<n;i++){
            printf("%d ",c[i]);
        }
        printf("\n");
    }
    return 0;
}