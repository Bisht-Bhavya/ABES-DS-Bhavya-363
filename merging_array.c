#include <stdio.h>
int main(){
    int n, m;
    int i = 0, j = 0, k = 0;
printf("Enter the size of two arrays: ");
scanf("%d %d", &n, &m);
int ar1[n], ar2[m], ar3[n + m];
printf("Enter the first sorted array: ");
for (int i = 0; i < n; i++) {
    scanf("%d", &ar1[i]);
}
printf("Enter the second sorted array: ");
for (int i = 0; i < m; i++) {
    scanf("%d", &ar2[i]);
}
while (i < n && j < m) {
    if (ar1[i] < ar2[j]) {
        ar3[k++] = ar1[i++];
    } else {
        ar3[k++] = ar2[j++];
    }
}
while (i < n) {
    ar3[k++] = ar1[i++];
}
while (j < m) {
    ar3[k++] = ar2[j++];
}
printf("Merged sorted array: ");
for ( i = 0; i < n + m; i++) {
    printf("%d ", ar3[i]);
}
printf("\n");
return 0;
}