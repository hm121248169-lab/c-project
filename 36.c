#include<stdio.h>

#define MOD 1000000007

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    
    // 创建二维数组存储结果
    long long a[1001][1001];
    
    // 初始化边界条件
    // 第一行和第一列
    for(int i = 1; i <= n; i++){
        a[i][1] = 1;
    }
    for(int j = 1; j <= m; j++){
        a[1][j] = 1;
    }
    
    // 根据递推关系填表
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++){
            a[i][j] = (a[i-1][j] + a[i][j-1]) % MOD;
        }
    }
    
    printf("%lld", a[n][m]);
    return 0;
}