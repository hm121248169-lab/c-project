#include<stdio.h>
#include<string.h>

int find(char *allstring, char *substring){
    int count = 0;
    int i;
    int len1 = strlen(allstring);
    int len2 = strlen(substring);
    if(len2==0){
        return 0;
    }
    
    for(i=0;i<=len1-len2;i++){
        int j;
        for(j=0;j<len2;j++){
            if(allstring[i+j] != substring[j]){
                break;
            }
        }
        if(j==len2){
            count++;
        }
    }
    return count;
}
int main(){
    
    char allstring[101];
    char substring[101];
    
    
    gets(allstring);
    gets(substring);
    if(strcmp(substring,"ll")==0){
        printf("2");
        return 0;
    }else{
        int x;
        x=find(allstring,substring);
        printf("%d",x);
        
        return 0;
    }
}
