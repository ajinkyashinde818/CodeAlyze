#include<iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    char a[n][n];
    for(int i=0;i<n;i++)cin >> a[i];
    char b[m][m];
    for(int i=0;i<m;i++)cin >> b[i];

    bool flg = false;
    for(int i=0;i<n-m+1;i++){
        for(int j=0;j<n-m+1;j++){
            if(a[i][j]==b[0][0]){
                flg = true;
                for(int k=0;k<m;k++){
                    for(int l=0;l<m;l++){
                        if(a[i+k][j+l]!=b[k][l]){
                            flg = false;
                            break;
                        }
                    }
                }
            }
            if(flg){
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
}
