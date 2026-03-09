#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        char x[12];
        scanf("%s",x);
        double a[8];
        int i;
        for(i=0;i<8;i++){
            scanf("%lf",&a[i]);
        }
        double sum=0;
        for(i=0;i<8;i++){
            sum+=a[i];
        }
        printf("%s:%lf\n",x,sum/8.0);

    }
    return 0;
}