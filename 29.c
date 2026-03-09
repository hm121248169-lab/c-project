#include <stdio.h>

int main() {
    int n;
    
    while (scanf("%d", &n) != EOF && n != 0) {
        int arr[20];  // 最多20个元素
        int *p;
        int max_value, max_index;
        
        // 读取n个整数到数组中
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        // 使用指针遍历数组找最大值和下标
        p = arr;           // 指向数组首元素
        max_value = *p;    // 初始化最大值为第一个元素
        max_index = 0;       // 初始化最大值下标为0
        
        // 遍历剩余元素
        for (int i = 1; i < n; i++) {
            p++;  // 移动指针到下一个元素
            if (*p > max_value) {
                max_value = *p;
                max_index = i;
            }
        }
        
        printf("%d %d\n", max_value, max_index);
    }
    
    return 0;
}