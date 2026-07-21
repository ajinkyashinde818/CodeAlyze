#include <bits/stdc++.h>
using namespace std;
int n;
long long m[222222];
long long sum,ans=1e15;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m[i];
        sum+=m[i];
    }
    for(int i=0;i<n-1;i++){
        sum-=m[i]; 
        sum-=m[i]; 
        if(sum < 0)ans=min(ans,-sum);
        else ans=min(ans,sum);
    }
    cout<<ans;
}
