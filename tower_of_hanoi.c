#include <stdio.h>

void toh(int n, char a, char b, char c){
    if(n==1){
        printf("Move disk 1 %c to %c \n", a, c);
        return;
    }
    toh(n-1, a,c,b);
    printf("Move disk %d %c to %c\n", n, a, c);
    toh(n-1, b,a,c);
}
int main(){
     toh(3,'A','B','C');
     printf("Done");
    return 0;
}