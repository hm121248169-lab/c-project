#include<stdio.h>

void answer(int a[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    int result[100];
    int left=0;
    int right=n-1;

    int pos;
    for(pos=0;pos<n;pos++){
        if(pos%2==0){
            result[pos]=a[left];
            left++;
        }else{
            result[pos]=a[right];
            right--;
        }
    }
    for(i=0;i<n;i++){
        a[i]=result[i];
    }
    
}

int main(){
    int t;
    scanf("%d",&t);
    int i;
    for(i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        int a[100];
        int j;
        for(j=0;j<n;j++){
            scanf("%d",&a[j]);
        }
        answer(a,n);
        for(j=0;j<n;j++){
            printf("%d ",a[j]);
        }
        printf("\n");
    }
    return 0;
}