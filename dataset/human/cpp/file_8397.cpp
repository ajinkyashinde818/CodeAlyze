#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check = true;

int main(){
    int n,m;
    cin >> n >> m;
    char a[50][50],b[50][50];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        cin >> a[i][j];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++)
        cin >> b[i][j];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            check = true;
            for(int k=0;k<m;k++){
                for(int l=0;l<m;l++){
                    if(a[i+k][j+l]!=b[k][l])check = false;
                }
            }
            if(check==true){cout << "Yes" << endl;return 0;}
        }
    }
    cout << "No" << endl;
    return 0;
}
