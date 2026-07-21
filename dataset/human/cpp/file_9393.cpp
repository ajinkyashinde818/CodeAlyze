#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b(m);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    for(int i = 0; i <= n-m; i++){
        for(int j = 0; j <= n-m; j++){
            bool flag = true;
            for(int k = i; k < i+m; k++){
                for(int l = j; l < j+m; l++){
                    if(a[k][l] != b[k-i][l-j]) flag = false;
                }
            }
            if(flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
