#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp_in, *fp_out;
    int ch;
    
    fp_in = fopen("chap14_file3.txt", "r");
    if (fp_in == NULL) {
        printf("无法打开输入文件\n");
        return 1;
    }
    
    fp_out = fopen("chap14_file3_bak.txt", "w");
    if (fp_out == NULL) {
        printf("无法创建输出文件\n");
        fclose(fp_in);
        return 1;
    }
    
    while ((ch = fgetc(fp_in)) != EOF) {
        if (!isspace(ch)) {
            fputc(ch, fp_out);
        }
    }
    
    fclose(fp_in);
    fclose(fp_out);
    
    return 0;
}