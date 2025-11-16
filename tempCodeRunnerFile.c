#include <stdio.h>
#define N 100

int count[N];
int m[5];
int b[5];

void sort(void);

int main() {
    int i;
    printf("Enter 5 countay elements: ");
    for (i = 0; i < 5; i++) {
        scanf("%d", &m[i]);
    }
    sort();
    printf("Sorted countay:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}

void sort() {
    int max = m[0];
    int i;

    for (i = 1; i < 5; i++) {
        if (m[i] > max) {
            max = m[i];
        }
    }

    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (i = 0; i < 5; i++) {
        count[m[i]]++;
    }

    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (i = 4; i >= 0; i--) {
        b[ count[m [ i ] ] - 1] = m [ i ];
        count[ m [ i ] ]--;
    }
}
