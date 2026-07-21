#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    char table[n][n];
    char tmp[m][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>table[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>tmp[i][j];
        }
    }
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<=n-m;j++){
            if(table[i][j]==tmp[0][0]){
                for(int k=0;k<m;k++){
                    for(int l=0;l<m;l++){
                        if(table[i+k][j+l]==tmp[k][l]){
                            continue;
                        }else{
                            goto Exit;
                        }
                    }
                }
                cout<<"Yes\n";
                return 0;
            }
            Exit:;
        }
    }
    cout<<"No\n";
}
