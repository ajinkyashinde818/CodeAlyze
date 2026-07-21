#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> a(n),b(m);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int j = 0; j < m; j++){
        cin >> b [j];
    }

    int x = a.at(0).size() - b.at(0).size();
    bool ans;
    for (int i = 0; i <= n-m; i++){
        ans = true;
        for (int j = 0; j <= x; j++){
            ans = true;
            for (int k = 0; k < m; k++){
                for (int l = 0; l < m; l++){
                    if (a[i+k][j+l] != b[k][l]){
                        ans = false;
                    }
                }
            }
            if (ans){
                    cout << "Yes" << endl;
                    return 0;
            }
        }
    }
    cout << "No" << endl;
}
