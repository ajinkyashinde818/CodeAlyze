#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    string a[n],b[m];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    bool ans=0;
    for(int i=0;i<=n-m;i++){
        for(int h=0;h<=n-m;h++){
            int count=0;
            for(int j=0;j<m;j++){
                for(int k=0;k<m;k++){
                    if(b[j][k]==a[i+j][h+k]){
                        count++;
                    }
                }
            }
            if(count==m*m){
                ans=1;
                break;
            }
        }
        if(ans) break;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
