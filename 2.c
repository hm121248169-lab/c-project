#include <stdio.h>
#include <string.h>

int main() {
  
    char s[1000];
	int exists[128] = {0};
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    int i; 
    for (i = 0; s[i] != '\0'; i++) {
        exists[(unsigned char)s[i]] = 1;
    }
    for (i = 0; i < 128; i++) {
        if (exists[i]) {
            putchar(i);
        }
    }
    putchar('\n');
    
    return 0;
}