#include<stdio.h>
#include<string.h>

int sum(char str[],char substr[]){
    int count=0;
    int str_len=strlen(str);
    int substr_len=strlen(substr);
    if(substr_len>str_len){
        return 0;
    }
    int i; // 遍历主字符串，检查每个可能位置是否匹配子串
    for(i=0;i<=str_len-substr_len;i++){
        int j; // 对比子串中的每个字符
        for(j=0;j<substr_len;j++){
            if(str[i+j]!=substr[j]){
                break;
            }
        }
        if(j==substr_len){
            count++;// 如果完全匹配，则计数加一
        }
    }
    return count;
}

int main(){
    int t;
    char str[201];
    char substr[201];
    scanf("%d",&t);
    int i;
    for(i=0;i<t;i++){
        scanf("%s",str);
        scanf("%s",substr);
        int result=sum(str,substr);
        printf("%d\n",result);
    }
    return 0;
}