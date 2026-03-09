#include <stdio.h>

int main() {
    int N;
    
    while (scanf("%d", &N) && N != 0) {
        int current_floor = 0;
        int total_time = 0;
        
        for (int i = 0; i < N; i++) {
            int target_floor;
            scanf("%d", &target_floor);
            
            // 计算移动时间
            if (target_floor > current_floor) {
                // 上升
                total_time += (target_floor - current_floor) * 6;
            } else if (target_floor < current_floor) {
                // 下降
                total_time += (current_floor - target_floor) * 4;
            }
            
            // 停留时间
            total_time += 5;
            
            // 更新当前楼层
            current_floor = target_floor;
        }
        
        printf("%d\n", total_time);
    }
    
    return 0;
}