#include<bits/stdc++.h>
using namespace std;

int main(){
        int n,m;cin >> n >> m;
        vector<int> v(n+m);
        for(int i=0;i<n;i++) v[i]=n-i;
        for(int i=0;i<m;i++) cin >> v[n+i];
        vector<bool> c(n+1,false);
        for(int i=n+m-1;i>=0;i--){
                if(c[v[i]]) continue;
                c[v[i]]=true;
                cout << v[i] << endl;
        }
        return 0;
}
