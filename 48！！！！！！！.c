#include <stdio.h>
#include <string.h>

#define MAX 1006  

int main() {
    char s[MAX];
    int T = 0;

    
    fgets(s, MAX, stdin);
   
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            T = T * 10 + (s[i] - '0');
        }
    }
    
    s[strcspn(s, "\n")] = '\0';
    printf("%sDAZE\n", s);

    
    for (int i = 0; i < T; i++) {
        fgets(s, MAX, stdin);
        s[strcspn(s, "\n")] = '\0';  
        if (strlen(s) > 0) {         
            printf("%sDAZE\n", s);
        }
    }

    return 0;
}
