#include<stdio.h>

int main(){
    int p,q;
    scanf("%d %d",&p,&q);
    int x=0,y=0;
    int n;
    scanf("%d",&n);
    char s[n];
    scanf("%s",s);
    int m;
    scanf("%d",&m);
    int i;
    int count=0;
    int a[m],b[m];
    for(i=0;i<m;i++){
        scanf("%d %d",&a[i],&b[i]);
    }
    // 使用二维数组标记障碍点
    char obstacle[1001][1001] = {0};  // 初始化为0

    for(i=0;i<m;i++){
        int ax, by;
        scanf("%d %d",&ax,&by);
        // 确保坐标在范围内才标记障碍
        if(ax >= 0 && ax <= p && by >= 0 && by <= q) {
            obstacle[ax][by] = 1;
        }
    }
    for(i=0;i<n;i++){
        switch(s[i]){
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
        }
        if(x==p+1){
            x=0;
        }
        if(x==-1){
            x=p;
        }
        if(y==q+1){
            y=0;
        }
        if(y==-1){
            y=q;
        }
        // O(1)时间复杂度检查障碍
        if(obstacle[x][y]){
            count++;
        }
    }
    printf("%d\n",count);
    printf("%d %d",x,y);
    return 0;
}