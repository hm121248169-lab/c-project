#include<stdio.h>

int main(){
    int n,m;
    scanf("%d",&n);
    switch(n){
        case 1:
            scanf("%d",&m);
            if(m>=1 && m<=31){
            printf("4\n");
            }else{
            printf("5\n");}
            break;
        case 2:
            scanf("%d",&m);
            if(m>=1 && m<=29){
            printf("4\n");
            }else{
            printf("5\n");}
            break;
        case 3:
            scanf("%d",&m);
            if(m>=1 && m<=31){
            printf("1\n");
            }else{
            printf("5\n");}
            break;
        case 4:
            scanf("%d",&m);
            if(m>=1 && m<=30){
            printf("1\n");
            }else{
            printf("5\n");}
            break;
        case 5:
            scanf("%d",&m);
            if(m>=1 && m<=31){
            printf("1\n");
            }else{
            printf("5\n");}
            break;
        case 6:
            scanf("%d",&m);
            if(m>=1 && m<=30){
            printf("2\n");
            }else{
            printf("5\n");}
            break;
        case 7:
            scanf("%d",&m);
            if(m>=1 && m<=31){
            printf("2\n");
            }else{
            printf("5\n");}
            break;
        case 8:
            scanf("%d",&m);
            if(m>=1 && m<=31){
            printf("2\n");
            }else{
            printf("5\n");}
            break;
        case 9:
            scanf("%d",&m);
            if(m>=1 && m<=30){
            printf("3\n");
            }else{
            printf("5\n");}
            break;
        case 10:
            scanf("%d",&m);
            if(m>=1 && m<=31){
            printf("3\n");
            }else{
            printf("5\n");}
            break;
        case 11:
            scanf("%d",&m);
            if(m>=1 && m<=30){
            printf("3\n");
            }else{
            printf("5\n");}
            break;
        case 12:
            scanf("%d",&m);
            if(m>=1 && m<=31){
            printf("4\n");
            }else{
            printf("5\n");}
            break;
        default:
            printf("5\n");
            break;
    }
    return 0;
}