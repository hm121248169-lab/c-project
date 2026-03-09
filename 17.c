#include<stdio.h>

double answer(int a, int b) {
    double temp = 1;
    int i;
    for(i=1; i<=b; i++){
        temp*=a;
    }   
    return temp;
}

double summary(int m, int n) {
    double sum = 0;
    int i;
    for(i=1; i<=m; i++){
        sum += answer(i, n);
    }
    return sum;
}
int main() {
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF){
        printf("%.0f\n", summary(m, n));
    
    }
    return 0;
}