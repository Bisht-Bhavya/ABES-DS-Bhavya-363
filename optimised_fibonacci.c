#include <stdio.h>
int DAT[1000];
int fib(int n){
    if(n==1 || n==2) {
    return DAT[n] = n-1;
    }else if(DAT[n] == 0){
        return DAT[n] = (fib(n-1) + fib(n-2));
    }
}

int main(){
    int n, i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        printf("%d ",fib(i));
    }
}

