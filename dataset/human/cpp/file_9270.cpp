#include <string>
#include <assert.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    bool isMatch = false;
    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
            isMatch = true;
            // b 
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < m; l++) {
                    if (a[i+k][j+l] != b[k][l]) isMatch = false;
                }
            }
            if (isMatch) break;
        }
        if (isMatch) break;
    }
    if (isMatch) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
