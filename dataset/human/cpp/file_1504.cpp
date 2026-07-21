#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
constexpr double EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max()/2;
constexpr int MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,cnt;cin>>n;
    bool f=false;
    vector<vector<int>> res(2*n);
    for(int i=1;i<=2*n;i++){
        if((2*n)%i!=0) continue;
        if(2*n/i-1 != i) continue;
        cnt=2*n/i;
        int idx=1;
        f=true;
        for(int j=0;j<2*n/i;j++){
            for(int k=0;k<i-j;k++){
                res[j].push_back(idx);
                res[j+k+1].push_back(idx);
                idx++;
            }
        }
        break;
    }
    if(!f){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++){
        int sz=res[i].size();
        cout<<sz;
        for(int j=0;j<sz;j++){
            cout<<" "<<res[i][j];
        }
        cout<<endl;
    }
}
