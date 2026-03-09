#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    
    // 脚数必须是偶数才有解
    if (a % 2 != 0) {
        printf("0 0\n");
        return 0;
    }
    
    // 最多动物数：全为鸡
    int max_animals = a / 2;
    
    // 最少动物数：尽可能多用兔子
    int min_animals = a / 4;
    if (a % 4 != 0) {
        // 如果不能被4整除，说明还有剩余脚数需要用鸡来补
        min_animals += 1;
    }
    
    printf("%d %d\n", min_animals, max_animals);
    
    return 0;
}