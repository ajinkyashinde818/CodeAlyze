#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b(m);

    for (int i = 0;i < n;i++){
        cin >> a.at(i);
    }
    for (int i = 0;i < m;i++){
        cin >> b.at(i);
    }
    bool ans = false;
    for (int i = 0;i <= n - m;i++){
        for (int j = 0;j <= n - m;j++){
             bool can = true;
             for (int k = 0;k < m;k++){
                 for (int l = 0;l < m;l++){
                     if (a[i+k][j+l] != b[k][l]){
                         can = false;
                         break;
                     }
                 }
             }
             if (can){
                 ans = true;
             }
        }
    }
    if (ans){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
