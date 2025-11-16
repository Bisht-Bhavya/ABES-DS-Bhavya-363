#include <stdio.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int divide(int arr[], int l, int h) {
    int p = arr[l];
    int i = l;
    int j = h;
    while (i < j) {
        while (arr[i] <= p && i <= h - 1) {
            i++;         }
        while (arr[j] > p && j >= l + 1) {
            j--;         }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[l], &arr[j]);
    return j;
}

void quickSort(int arr[], int l, int h) {
    if (l < h) {
        int pi = divide(arr, l, h);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, h);
    }
}

int main() {
     printf("Enter array size: ");
     int n;
     scanf("%d", &n);
     int arr[n];
     printf("Enter %d elements: ", n);
     for(int i = 0; i < n; i++) {
         scanf("%d", &arr[i]);
     }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}