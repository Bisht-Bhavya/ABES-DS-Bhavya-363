#include <stdio.h>
int fib(int n){
    if(n==1 || n==2) return n-1;

return fib(n-1) + fib(n-2);
}

int main(){
    int n, i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        printf("%d ",fib(i));
    }
}

