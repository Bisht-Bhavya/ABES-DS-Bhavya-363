#include <stdio.h>
void main(){
    int n,j,temp,sw;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 1; i < n; i++){
        temp = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > temp){
            sw = arr[j];
            arr[j] = arr[j + 1 ];
            arr[j + 1] = sw;
            j--;
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}