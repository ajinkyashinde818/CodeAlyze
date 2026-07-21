#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,m;
    cin >> n >> m;
    char a[n][n];
    char b[m][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }
    int x = n - m + 1;
    
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            int t = 1;
            for(int k = 0; k < m; k++){
                for(int l = 0; l < m; l++){
                    if(a[i+k][j+l] != b[k][l]){
                        t = 0;
                    }
                }
            }
            if(t == 1){
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
}
