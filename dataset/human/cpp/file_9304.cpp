#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n, m;
    cin >> n >> m;
    string a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j + m > n) continue;
            if (i + m > n) continue;
            int jud = 0;
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < m; l++) {
                    if(b[k][l] != a[i + k][j + l]) jud++;
                }
            }
            if (jud == 0) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
