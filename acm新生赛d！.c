#include<stdio.h>
#include<string.h>
int prime[100001];
// 创建质数表 - 用数组标记哪些是质数
void create_prime(int m){
    // 创建质数表 - 用数组标记哪些是质数
          // 初始化为0
    for(int i = 0; i <= m; i++) {
        prime[i] = 1;  // 先假设都是质数
    }
    prime[0] = prime[1] = 0;// 初始化为0
        // 筛选质数：把不是质数的标记为0
    for(int i = 2; i*i <= m; i++) {
        if(prime[i] == 1) {  // 如果是质数
            for(int j = i*i; j <= m; j += i) {  // 把它的倍数都标记为非质数
                prime[j] = 0;
            }
         }
    }
} 
    
int main(){
    create_prime(100000);  // 预处理质数表，范围到100000    
    int T;
    scanf("%d", &T);
    
    while(T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        char s[n+1];
        scanf("%s", s);
        
        
        // 找子串对应的数字
        int found[100001] = {0};  // 记录找到的质数
        for(int i = 0; i < n; i++) {
            int num = 0;
            for(int j = i; j < n && j<i+18; j++) {//！！！限制子串长度不超过18位（因为2^17 < 10^5 < 2^18），避免整数溢出，同时减少不必要的计算
                num = num * 2 + (s[j] - '0');  // 二进制转十进制
                
                if(num > m) break;  // 超过m就跳出
                
                if(prime[num] == 1) {  // 如果是质数
                    found[num] = 1;  // 标记找到了
                }
            }
        }
        
        // 找最小和最大的质数
        int min = -1, max = -1;
        for(int i = 2; i <= m; i++) {
            if(found[i] == 1) {
                if(min == -1) min = i;  // 第一个找到的是最小的
                max = i;  // 最后一个就是最大的
            }
        }
        
        if(min == -1) {
            printf("-1\n");
        } else {
            printf("%d %d\n", min, max);
        }
    }
    
    return 0;
}