#include <stdio.h>

int main() {
    FILE *fp;
    int count = 0;
    int ch;
    int in_word = 0;
    
    fp = fopen("chap14_file2.txt", "r");
    
    if (fp == NULL) {
        printf("无法打开文件\n");
        return 1;
    }
    
    while ((ch = fgetc(fp)) != EOF) {
        if (ch != ' ' && ch != '\n' && ch != '\t' && ch != '\r') {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }
    
    fclose(fp);
    
    printf("%d\n", count);
    
    return 0;
}