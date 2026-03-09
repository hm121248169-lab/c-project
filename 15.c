#include<stdio.h>
#include<string.h>
int answer(char s[]){
    int count=0;  
    int len=strlen(s);
    
    int i;
    for(i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            count++;
        }
    }
    return count;
}
int main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        char s[101];
        scanf("%s",s);
        printf("%d\n",answer(s));
    }
    return 0;
}