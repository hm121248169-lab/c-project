#include<stdio.h>

int answer(int m){
    int sum=0;
    int i;
    for(i=1;i<m;i++){
        if(m%i==0){
            sum+=i;
        }
    }
    if(sum==m){
        return 1;
    }
    else{
        return 0;
    }
    
}

int main(){
    int m;
    while(scanf("%d",&m)!=EOF){
        if(answer(m)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}