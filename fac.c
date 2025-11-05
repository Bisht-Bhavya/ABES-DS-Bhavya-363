#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    n = recur(n);
    printf("%d ",n);    
 
}
int recur(int n){
    if( n == 1) return 1;
    return n * recur(n-1);
}