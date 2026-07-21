#include <bits/stdc++.h>

using namespace std;

//const int MOD=1e9+7;
const int MOD=998244353;

const double PI=3.14159265359;




int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    
    int k=-1;
    for(int i=2; i<1000; i++){
        if(2*n==i*(i-1)) k=i;
    }
    if(k==-1){
        cout<<"No";
        return 0;
    }
    
    vector<vector<int>> ans(k,vector<int>(k-1,-1));
    
    int cur=1;
    for(int i=0; i<k-1; i++){
        for(int j=i; j<k-1; j++){
            ans[i][j]=cur;
            ans[j+1][i]=cur;
            cur++;
        }
    }
    
    cout<<"Yes\n"<<k<<'\n';
    for(int i=0; i<k; i++){
        cout<<k-1<<' ';
        for(int j:ans[i]){
            cout<<j<<' ';
        }
        cout<<'\n';
    }
    
    
    return 0;
}
