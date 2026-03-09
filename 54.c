#include<stdio.h>
#include<string.h>

void change(char s[100],int k){
    int i;
    for(i=0;i<100;i++){
        s[i]+=k;

    }
}

int main(){
    char s[100];
    int k;
    int i;
    for(i=0;i<100;i++){
        scanf("%c",&s[i]);
    }
    change(s,k);
    for(i=0;i<100;i++){
        printf("%c",s[i]);
    }
}