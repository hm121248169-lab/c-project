#include<stdio.h>
#include<string.h>

void paixu(char str[101]){
    int i,j,len;
    char temp;
    len=strlen(str);
    for(i=0;i<len-1;i++){
        for(j=0;j<len-1-i;j++){
            if(str[j]>='0' && str[j]<='9'){
                temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }
        
    }
    for(i=0;i<len-1;i++){
        for(j=0;j<len-1-i;j++){
            if(str[j]>='0' && str[j]<='9'){
                temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }
        
    }
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        char str[101];
        scanf("%s",str);
        paixu(str);
        printf("%s\n",str);
    }
    return 0;
}