#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    char a[100][100],b[100][100];
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

    bool seg = false;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n;j++){
            if(i+m-1 >= n || j+m-1 >= n){
                continue;
            }

            bool ans = true;
            for(int k = 0; k < m; k++){
                for(int l = 0; l < m; l++){
                    if(a[i+k][j+l] != b[k][l]){//ここが肝
                        ans = false;
                    }
                }
            }
            if(ans){
                    seg = true;
                }
        }
    }
    if(seg){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


    return 0;
}
