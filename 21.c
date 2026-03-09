#include<stdio.h>

void zhuan(int a[10][10],int b[10][10],int x,int y){
    int i,j;
    
    for(i=0;i<y;i++){
        for(j=0;j<x;j++){
            b[i][j]=a[j][i];
          
        }
        
    }
   
}


int main(){
    int a[10][10];
    int i,j;
    int x,y;
    scanf("%d%d",&x,&y);
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int b[10][10];
    zhuan(a,b,x,y);
    for(i=0;i<y;i++){
        for(j=0;j<x;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}