#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int i;
    int count=0;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        if(a[i]!=i+1){
            int j;
            for(j=i+1;j<n;j++){
                if(a[j]==i+1){
                    int temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                    count++;
                }
            }
        }
    }
    printf("%d",count);
    return 0;
}