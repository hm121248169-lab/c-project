#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    char *s[n];
    char *max;
    int i;
    for(i=0; i<n; i++){
        s[i] = (char*)malloc(n*sizeof(char));
        scanf("%s", s[i]);
    }
    max = s[0];
    for(i=1; i<n; i++){
        if(strcmp(s[i], max) > 0){
            max = s[i];
        }
    }
    printf("%s", max);
    for(i=0; i<n; i++){
        free(s[i]);
    }
    return 0;
}