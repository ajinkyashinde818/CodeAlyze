#include "bits/stdc++.h"
using namespace std;

string a[55], b[55];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < m; ++i) cin >> b[i];


    for(int i = 0; i + m - 1 < n; ++i) 
        for(int j = 0; j + m - 1 < n; ++j) {
            bool ok = true;
            for(int k = 0; k < m; ++k) {
                string s = a[i + k].substr(j, m);
                if(s != b[k]) ok = false;
            }
            if(ok) return !printf("Yes");
        }

    puts("No");
}
