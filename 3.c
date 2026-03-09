#include<stdio.h>
int main(){
    int m;
    scanf("%d",&m);
    int i;
    int a[20];
    for(i=0;i < m; i++){
        scanf("%d",&a[i]);
    }
    int n;
    scanf("%d",&n);
    int b[20];
    for(i = 0; i < n;i++){
        scanf("%d",&b[i]);
    }
    int x = 0;
    int c[40];
    for(i = 0;i < m; i++){
        c[x++] = a[i];
    }
    int j;
    for(i = 0;i < n; i++){
        int found = 0;
        for(j = 0; j < m; j++){
            if(b[i] == a[j]){
                found = 1;
                break;
            }
        }
        if(found == 0){
            c[x++] = b[i];
        }
    }
    
    for(i = 0; i < x-1;i++){
        for(j = 0; j<x-i-1; j++){
            if(c[j] < c[j+1]){
                int t = c[j];
                c[j] = c[j+1];
                c[j+1] = t;
            }
        }
    }
    for(i = 0; i < x;i++){
        printf("%d ",c[i]);
    }
    return 0;
}