#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
const int N=1e5+10;
int n;
ll tot;
ll d[N],w[N],benef[N];
void prepare(){
        cin>>n>>tot;
        for(int i=1;i<=n;i++) cin>>d[i]>>w[i];
}

ll solve(){
        ll ans=0;
        ///1->i
        for(int pha=0;pha<=1;pha++){
                ll sum=0;
                for(int i=1;i<=n;i++) {
                        sum+=w[i];
                        benef[i]=max(sum-d[i],benef[i-1]);
                }
                ans=max(ans,benef[n]);
                sum=0;
                for(int i=n;i>=1;i--){
                        sum+=w[i];
                        ans=max(ans,sum-(tot-d[i]));
                        ans=max(ans,sum-2*(tot-d[i])+benef[i-1]);
                        
                }
                for(int i=1;i<=n;i++) d[i]=tot-d[i];
                reverse(d+1,d+n+1);
                reverse(w+1,w+n+1);
              
        }
        return ans;
}
int main(){
        prepare();
        cout<<solve();
}
