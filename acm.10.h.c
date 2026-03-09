#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    int i;
    for (i = 0; i < T; i++) {
        int Y, N;
        scanf("%d %d", &Y, &N);
        
        int count = 0;
        int year = Y;
        
        while (count < N) {
            // 判断闰年：能被4整除但不能被100整除，或者能被400整除
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                count = count + 1;
            }
            
            if (count < N) {
                year = year + 1;
            }
        }
        
        printf("%d\n", year);
    }
    
    return 0;
}