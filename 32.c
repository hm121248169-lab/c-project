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
        int sum=0;
        for(i=0;i<n;i++){
            sum+=s[i];
        }
        double avg=(double)sum/n;
        printf("%.4f\n",avg);
        free(s);
    }
}