#include<stdio.h>
#include<math.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    long long sum=a;
    
    while(b--){
        sum*=a;
    }
    int date=sum%7;
    switch (date)
    {
    case 0:
        printf("Sunday");
        break;
    
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;
    default:
        break;
    }
    

    return 0;
}