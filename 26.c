#include<stdio.h>
#include<string.h>

void chang(char *p){
    while(*p!='\0'){
        if(*p>='a' && *p<='z'){
            *p = *p - ('a' - 'A');
        }
        p++;
    }
}

int main(){
    char s[101];
    while(gets(s)!=NULL){
        chang(s);
        printf("%s\n",s);
    }
    return 0;
}