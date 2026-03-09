#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int a;
        scanf("%d", &a);
        if(a%2!=0){
            printf("0 0\n");
            continue;
        }
        if(a<2){
            printf("0 0\n");
            continue;
        }
        int max=a/2;
        int min=(a+3)/4;//向上取整  26/4=6.5->7  等价于ceil(a/4.0)
        int found=0;
        for(int y=min;y>=0;y--){
            int x=min-y;
            if(2*x+4*y==a){
                found=1;
                break;
            }
        }
        if(found){
            printf("%d %d\n", min, max);
        }else{
            printf("0 0\n");
        }
    }
    return 0;
}