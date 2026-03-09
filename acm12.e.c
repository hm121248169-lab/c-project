#include <stdio.h>

int main() {
    int L, M;
    scanf("%d %d", &L, &M);
    
    // 创建一个数组表示每棵树是否存在，1表示存在，0表示被移走
    int tree[10001] = {0};
    
    // 初始化所有树都存在
    for (int i = 0; i <= L; i++) {
        tree[i] = 1;
    }
    
    // 处理每个施工区域
    for (int i = 0; i < M; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        
        // 将该区域内的树标记为移走
        for (int j = start; j <= end; j++) {
            tree[j] = 0;
        }
    }
    
    // 统计剩余的树
    int count = 0;
    for (int i = 0; i <= L; i++) {
        if (tree[i] == 1) {
            count++;
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}