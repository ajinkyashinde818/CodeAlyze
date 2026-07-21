#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007LL;
long long GCD(long long a, long long b){return b == 0 ? a : GCD(b, a % b);}

vector<string> a, b;

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;

    cin >> n >>m;

    for(int i = 0; i < n; ++i){
        string c;
        cin >> c;
        a.push_back(c);
    }

    for(int i = 0; i < m; ++i){
        string c;
        cin >> c;
        b.push_back(c);
    }

    for(int x = 0; x <= n - m; ++x){
        for(int y = 0; y <= n - m; ++y){
            bool found = true;
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < m; ++j){
                    if(a[x + i][y + j] != b[i][j]){
                        found = false;
                        break;
                    }
                }
            }
            if(found){
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";

    return 0;
}
