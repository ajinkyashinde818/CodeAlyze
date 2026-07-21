#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    int n,m;
    cin >> n >> m;
    string a[n],b[m];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    if(n == m){
        bool ans = true;
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]) ans = false;
        }
        if(ans){
            cout << "Yes" << endl;
            return 0;
        }
    }

    for(int i = 0; i < n-m; i++){
        for(int j = 0; j < n-m; j++){
            bool same = true;
            for(int k = 0; k < m; k++){
                bool end = false;
                for(int l = 0; l < m; l++){
                    if(a[k+i][l+j] != b[k][l]){
                        end = true;
                        same = false;
                        break;
                    }
                }
                if(end) break;
            }
            if(same){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
