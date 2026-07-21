#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;

int main()
{
    int n, m;
    int i, j, k, l, key, judge = 0;
    
    cin >> n >> m;
    
    vector<string> a(n, ""), b(m, "");
    
    for(i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(j = 0; j < m; j++) {
        cin >> b[j];
    }
    
    for(i = 0; (i <= n - m) && (judge == 0); i++) {
        for(j = 0; (j <= n - m) && (judge == 0); j++) {
            
            key = 1;
            for(k = 0; (k < m) && (key == 1); k++) {
                for(l = 0; (l < m) && (key == 1); l++) {
                    
                    if(b[k][l] != a[i+k][j+l]) {
                        key = 0;
                    }
                }
            }
            if(key == 1) {
                judge = 1;
            }
        }
    }
    
    if(judge == 1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    
    return 0;
}
