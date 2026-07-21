#include <bits/stdc++.h>

using namespace std;

int main(){
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout<<fixed;*/

    vector<int> v(3);
    int n,ans=0;
    for(int i=0;i<3;i++){
        cin>>v[i];
    }
    cin>>n;
    for(int i=0;i<3001;i++){
        for(int j=0;j<3001;j++){
            if((n-i*v[0]-j*v[1])%v[2]==0&&(n-i*v[0]-j*v[1])>=0){
                ans++;
            }
        }
    }
    cout<<ans;

    return 0;
}
