#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        int *s=(int*)malloc(n*sizeof(int));
        if(s==NULL){
            return 1;
        }
        int i;
        for(i=0;i<n;i++){
            scanf("%d",&s[i]);
        }
        int no=0;
        for(i=0;i<n;i++){
            if(s[i]<60){
                no++;
            }

        }
        printf("%d\n",no);
        free(s);
    }
}