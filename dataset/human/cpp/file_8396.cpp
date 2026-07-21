#include <bits/stdc++.h>

using namespace std;

const int N = 55;
int n, m;
string a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    int maxle = n - m;

    for(int i = 0; i <= maxle; i++){
        for(int j = 0; j <= maxle; j++){
            bool can = true;
            for(int k = i; k <= i + m - 1; k++){
                if(a[k].substr(j, m) != b[k - i]){
                    can = false;
                }
            }
            if(can){
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}
