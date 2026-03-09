#include<stdio.h>

#define N 305

int main(){
    int a[N], n, m, p, i, cn, pm;
    while(1){
        scanf("%d%d%d", &n, &p, &m);
        if(n == 0 && p == 0 && m == 0)
            break;
        
        // 初始化数组，a[i]存储第i个位置上的人的编号(1~n)
        for(i = 0; i < n; i++)
            a[i] = i+1;
            
        cn = 0;           // 已出圈人数
        i = p - 2;        // 当前位置，从p的前一个位置开始（因为循环中先i++）
        pm = 0;           // 报数
        
        int first = 1;    // 标记是否是第一个输出
        
        // 循环淘汰人员，直到所有人都出圈
        while(cn < n){
            i++;
            if(i == n)
                i = 0;
                
            // 如果当前位置上的人未被淘汰
            if(a[i] != 0){
                pm = pm + 1;
                // 报数达到m时，淘汰此人
                if(pm == m){
                    if(!first){
                        printf(",");
                    }
                    printf("%d", a[i]);  // 输出出圈的小孩编号
                    a[i] = 0;            // 标记为已淘汰
                    pm = 0;              // 重置报数器
                    cn = cn + 1;         // 增加已淘汰人数计数
                    first = 0;
                }
            }
        }
        printf("\n");
    }
    return 0;
}


