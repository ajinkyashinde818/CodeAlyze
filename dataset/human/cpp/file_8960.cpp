#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    char temp[n][n];
    char image[m][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>temp[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cin>>image[i][j];
        }
    }
    bool ok = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i+(m-1) >= n || j+(m-1) >= n) continue;
            bool match = true;
            for(int k = 0; k < m; k++){
                for(int l = 0; l < m; l++){
                    if(temp[i+k][j+l] != image[k][l]) match = false;
                }
            }
            if(match) ok = true;
        }
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
