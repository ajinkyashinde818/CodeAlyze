#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, i, j, k, l, f = 0;
    cin >> n >> m;
    char a[n][n], b[m][m];
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    for(i=0; i<m; i++){
        for(j=0; j<m; j++){
            cin >> b[i][j];
        }
    }
    for(i=0; i<n-m+1; i++){
        for(j=0; j<n-m+1; j++){
            f = 0;
            for(k=0; k<m; k++){
                for(l=0; l<m; l++){
                    if(a[i+k][j+l] != b[k][l]){
                        f = 1;
                        break;
                    }
                    if(k == m-1 && l == m-1){
                        cout << "Yes";
                        return 0;
                    }
                }
                if(f == 1) break;
            }
        }
    }
    cout << "No";
    return 0;
}
