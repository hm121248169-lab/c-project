#include<stdio.h>
#include<string.h>

int main(){
    int n;
    scanf("%d",&n);
    int i;
    int find=0;
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        if(a[i]%2==1){
            find=1;
        }
    }
    if(find==1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}