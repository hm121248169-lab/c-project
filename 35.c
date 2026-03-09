#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int i;
    int find=0;
    for(i=1;i<=n;i++){
        if(i%4!=0){
            find=0;
            int a=i;
            while(a>0){
                int k=a%10;
                a=a/10;
                if(k==4){
                    find=1;
                    break;
                }
            }
            if(find==0){
                printf("%d\n",i);
                
            }
        }
        
    }
    return 0;
}