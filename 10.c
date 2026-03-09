#include<stdio.h>

void input(int a[][10],int m,int n){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
}
void add(int num1[][10],int num2[][10],int result[][20],int m,int n){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            result[i][j]=num1[i][j]+num2[i][j];
        }
    }
}
void output(int result[][20],int m,int n){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int num1[10][10],num2[10][10],result[20][20];
    input(num1,m,n);
    input(num2,m,n);
    add(num1,num2,result,m,n);
    output(result,m,n);
    return 0;
}
