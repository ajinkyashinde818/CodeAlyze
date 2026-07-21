#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<char>> a(n+10,vector<char>(n+10)),b(m+10,vector<char>(m+10));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
        cin >> a[i][j];
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
        cin >> b[i][j];
        }
    }
    bool flag;
    int ans = 0;
    for(int i = 1; i <= n-m+1; i++){
        for(int j = 1; j <= n-m+1; j++){
            flag = true;
            for(int k = 1; k <= m; k++){
                for(int h = 1; h <= m; h++){
                    if(a[k+i-1][h+j-1] != b[k][h]){
                        flag = false;
                    }
                }
            }
            if(flag){
                ans++;
            }
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
