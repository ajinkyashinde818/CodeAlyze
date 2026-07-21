#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    int n,m;
    cin >> n>>m;
    vector<string> a(n);
    vector<string> b(n);
    bool f=true;
    bool f_tf=true;
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    for(int i=0;i<m;i++){
        cin >>b[i];
    }
    for(int i=0;i<n-m;i++){
        for(int j=0;j<n-m;j++){
            for(int k=0;k<m;k++){
                f_tf=true;
                if(a[i+k].substr(j,m)!=b[k]){
                    f=false;
                    f_tf=false;
                    break;
                }
            }
            if(f_tf==true) break;
        }
        if(f_tf==true)break;
    }
    if(f_tf==true) cout << "Yes"<<endl;
    else cout << "No" <<endl;
}
