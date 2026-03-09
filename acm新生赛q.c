#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n;
    scanf("%d", &n);
    
    int q[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }
    
    // f[i] 表示以品质 i 结尾的最长非递减子序列长度
    int f[5] = {0};
    
    for (int i = 0; i < n; i++) {
        int x = q[i];
        // 寻找所有小于等于x的品质中，最长的非递减子序列
        int max_len = 0;
        for (int j = 0; j <= x; j++) {
            if (f[j] > max_len) {
                max_len = f[j];
            }
        }
        // 以x结尾的最长非递减子序列长度是max_len + 1
        f[x] = max_len + 1;
    }
    
    // 找到所有品质中最大的非递减子序列长度
    int max_length = 0;
    for (int i = 0; i < 5; i++) {
        if (f[i] > max_length) {
            max_length = f[i];
        }
    }
    
    printf("%d\n", n - max_length);
    
    return 0;
}