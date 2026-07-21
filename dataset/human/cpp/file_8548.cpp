#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    string a[n];
    string b[m];

    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    
    for(int i=0;i<n-m+1;i++){
        for(int j=0;j<n-m+1;j++){
            bool flag = true;
            for(int k=0;k<m;k++){
                for(int u=0;u<m;u++){
                    if(a[i+k][j+u]!=b[k][u]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
