#include<stdio.h>
#include<string.h>

double avarage(int a[],int n)
{
	int i,sum=0;
    
    for(i=0;i<n;i++)
    {
        sum+=a[i];
    }
    
    return (double)sum/n;
}

int main(){
    int a[100];
    int n;
    while(scanf("%d",&n)!=EOF){
    
        int i;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        double avg=avarage(a,n);
        printf("%.4lf\n",avg);
    }      
        
        return 0;
}

