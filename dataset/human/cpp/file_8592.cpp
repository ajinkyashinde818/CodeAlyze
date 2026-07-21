#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    long n,m;
    cin>>n>>m;
    vector<string> a(n),b(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    for(int i = 0; i < m; i++)
        cin>>b[i];
    for(int i = 0; i <=n-m; i++){
        for(int j = 0; j <=n-m; j++){
            bool jud=true;
            for(int k = 0; k < m; k++){
                if(b[k]!=a[j+k].substr(i,m)){
                    jud=false;
                    break;
                }
            }
            if(jud){
                cout<<"Yes";
                return 0;
            }
        }
    }
    cout<<"No";
}
