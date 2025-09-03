#include <iostream>
using namespace std;

int main() {
    int n, m,i,j;
    cout << "Enter the size of two sets: ";
    cin >> n >> m;

    int set1[n], set2[m], inter[min(n, m)];
    int k = 0;
    cout << "Enter elements of the first set: ";
    for ( i = 0; i < n; i++) {
        cin >> set1[i];
    }
    cout << "Enter elements of the second set: ";
    for ( i = 0; i < m; i++) {
        cin >> set2[i];
    }
    for ( i = 0; i < n; i++) {
        int flag = 0;
        for (j = 0; j < m; j++) {
            if (set1[i] == set2[j]) {
                int present = 0;
                for (int x = 0; x < k; x++) {
                    if (inter[x] == set1[i]) {
                        present = 1;
                        break;
                    }
                }
                if (present == 0) {
                    inter[k++] = set1[i];
                }
                flag = 1;
                break;
            }
        }
    }

    cout << "First set: ";
    for (i = 0; i < n; i++) cout << set1[i] << " ";
    cout << "\n";

    cout << "Second set: ";
    for (i = 0; i < m; i++) cout << set2[i] << " ";
    cout << "\n";

    cout << "Intersection: ";
    if (k == 0) cout << "Empty set";
    else for (i = 0; i < k; i++) cout << inter[i] << " ";
    cout << "\n";

    return 0;
}
