#include<stdio.h>
#include<string.h>

int main(){
    int n;
    scanf("%d",&n);
    int count=n;
    int a[n],b[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i],&b[i]);
    }
    for(i=0;i<n;i++){
        int j;
        for(j=i+1;j<n;j++){
            if(a[i]==a[j]){
                if(b[i]==-b[j]){
                    count--;
                }
            }
        }
    }       

    printf("%d\n",count);
    return 0;
}