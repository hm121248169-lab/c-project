#include<stdio.h>

int main(){
    int sx,sy,tx,ty;
    scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
    int dx=tx-sx;
    int dy=ty-sy;
    if(dx<0){
        dx=-dx;
    }
    if(dy<0){
        dy=-dy;
    }
    printf("%d\n",dx+dy);
    return 0;
}