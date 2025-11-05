#include <stdio.h>
int main(){
    int n, i, l = 0,  h = 9;
    printf("Size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array: ");
for(i = 0; i < 10; i++){
    scanf("%d", &arr[i]);
}
for(i = 0; i < 10; i++){
    printf("%d ");
}
printf("\n");
printf("Sorted array:\n");
sort(arr);
    return 0;
}
void sort(int *arr, int l,int  h){
    int mid;
     if( l < h){
     mid = ( l + h ) / 2;
     sort(arr,l, mid);
     sort(arr, mid + 1, h);
     merge(arr, l ,h, mid);
     }
}
void merge(int arr, int l, int h, int mid){
int i;

}