#include <stdio.h>
#include <string.h>

int main(){
    int m;
    scanf("%d",&m);
    while(m--){
        int n;
        scanf("%d",&n);
        
        int i;
        int odd_count = 0, even_count = 0;
        
        for(i=0; i<n; i++){
            int num;
            scanf("%d",&num);
            if(num % 2 == 1){
                odd_count++;
            }else{
                even_count++;
            }
        }
        
        // 要选出6个数使其和为奇数，需要奇数个奇数
        // 即：1个奇数+5个偶数，或3个奇数+3个偶数，或5个奇数+1个偶数
        int possible = 0;
        
        // 1个奇数 + 5个偶数
        if(odd_count >= 1 && even_count >= 5) possible = 1;
        // 3个奇数 + 3个偶数
        if(odd_count >= 3 && even_count >= 3) possible = 1;
        // 5个奇数 + 1个偶数
        if(odd_count >= 5 && even_count >= 1) possible = 1;
        
        if(possible){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}