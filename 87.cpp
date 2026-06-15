#include <stdio.h>

int main() {
    FILE *fp;
    int count = 0;
    char ch;
    
    fp = fopen("chap14_file1.txt", "r");
    
    if (fp == NULL) {
        printf("无法打开文件\n");
        return 1;
    }
    
    while ((ch = fgetc(fp)) != EOF) {
        count++;
    }
    
    fclose(fp);
    
    printf("%d\n", count);
    
    return 0;
}