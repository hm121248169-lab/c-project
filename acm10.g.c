#include <stdio.h>
#include <math.h>

const double PI = 4*atan(1);
int main() {
    int n,i,year;
    double x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lf%lf",&x,&y);
        year=(int)(PI*(x*x+y*y)/100+1);
        printf("Property %d: This property will begin eroding in year %d.\n",i,year);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}