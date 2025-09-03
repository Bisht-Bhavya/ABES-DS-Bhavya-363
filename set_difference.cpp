#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter the size of the first set: ";
    cin >> n;
    cout << "Enter the size of the second set: ";
    cin >> m;
    int i, flag;
    int set1[n], set2[m], diff[n];
    int k = 0;

    cout << "Enter elements of the first set: ";
    for ( i = 0; i < n; i++) cin >> set1[i];

    cout << "Enter elements of the second set: ";
    for ( i = 0; i < m; i++) cin >> set2[i];

    for ( i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < m; j++) {
            if (set1[i] == set2[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            diff[k++] = set1[i];
        }
    }

    cout << "First set: ";
    for ( i = 0; i < n; i++) cout << set1[i] << " ";
    cout << "\n";

    cout << "Second set: ";
    for ( i = 0; i < m; i++) cout << set2[i] << " ";
    cout << "\n";

    cout << "Difference (A - B): ";
    if (k == 0) cout << "∅";
    else for ( i = 0; i < k; i++) cout << diff[i] << " ";
}
