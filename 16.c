#include<stdio.h>

int answer(int n){
    int i;
    for(i=2;i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(answer(n)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
    
}