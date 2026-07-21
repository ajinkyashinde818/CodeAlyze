#include <iostream>

using namespace std;

const int kMaxN = 50;

int main() {
    int n, m;
    string A[kMaxN], B[kMaxN];

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < (n - m + 1); i++) {
        for (int j = 0; j < (n - m + 1); j++) {
            bool flag = true;
            for (int k = i; k < (i + m); k++) {
                for (int l = j; l < (j + m); l++) {
                    if (A[k][l] != B[k - i][l - j]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) {
                    break;
                }
            }
            if (flag) {
                cout << "Yes" << endl;
              	return 0;
            }
        }
    }

    cout << "No" << endl;
}
