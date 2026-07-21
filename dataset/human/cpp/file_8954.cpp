#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for(ll i = 0;i < n;i++){
        cin >> a[i];
    }
    for(ll i = 0;i < m;i++){
        cin >> b[i];
    }

    for(ll i = 0;i < n - m + 1;i++){
        for(ll j = 0;j < n - m + 1;j++){
            bool f = false;
            for(ll k = 0;k < m;k++){
                for(ll l = 0;l < m;l++){
                    if(a[i + k][j + l] != b[k][l]){
                        f = true;
                    }
                }
            }
            if(!f){
                cout << "Yes";

                return 0;
            }
        }
    }

    cout << "No";

    return 0;
}
