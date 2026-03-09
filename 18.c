#include<stdio.h>

int input(int a[][10],int m,int n){
    
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    return 0;
}

int output(int a[][10],int m,int n){
    
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int  main(){
    int a[10][10];
    int m,n;
    scanf("%d %d",&m,&n);
    input(a,m,n);
    output(a,m,n);
    return 0;
}