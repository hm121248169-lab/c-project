#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    int distance;
    char line[1000];
    
    scanf("%d", &distance);
    getchar(); // 处理整数后的回车符
    
    distance = distance % 26; // 确保距离在0-25范围内
    
    fp = fopen("encipherment.txt", "w");
    if (fp == NULL) {
        printf("无法创建文件\n");
        return 1;
    }
    
    while (fgets(line, sizeof(line), stdin) != NULL) {
        for (int i = 0; line[i] != '\0'; i++) {
            char ch = line[i];
            
            if (isalpha(ch)) {
                char base = isupper(ch) ? 'A' : 'a';
                ch = (ch - base + distance) % 26 + base;
            }
            
            fputc(ch, fp);
        }
    }
    
    fclose(fp);
    
    return 0;
}