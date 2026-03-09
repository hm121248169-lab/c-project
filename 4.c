#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    scanf("%s",str);
    int len=strlen(str);
    int i;
    for(i=0;i<len-1;i++){
        int j;
        for(j=0;j<len-i-1;j++){
            if(str[j]>str[j+1]){
                char t=str[j];
                str[j]=str[j+1];
                str[j+1]=t;
            }
        }
    }
    printf("%c",str[0]);
    for(i=1;i<len;i++){
        if(str[i]!=str[i-1]){
            printf("%c",str[i]);
        }
    }
    return 0;
}