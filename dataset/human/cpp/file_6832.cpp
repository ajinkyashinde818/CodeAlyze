#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N;
ll A[200010],B[200010];
ll cntA[200010],cntB[200010];
int main(){
    cin>>N;
    for(ll i=0;i<N;i++) cin>>A[i];
    for(ll i=N-1;i>=0;i--) cin>>B[i];

    for(ll i=0;i<N;i++){
        cntA[A[i]]++; cntB[B[i]]++;
    }
    for(ll i=0;i<N;i++){
        if(A[i]==B[i]){
            if(cntA[A[i]]+cntB[B[i]]>N){
                cout<<"No"<<endl;
                return 0;
            }
            ll bs=i;
            while(B[bs]==A[i])bs++;
            ll as=i;
            while(A[as]==A[i])as++;
            ll start=max(as,bs);

            ll e=i;
            while(A[e]==B[e])e++;

            ll index=i;
            if(A[i-1]==A[i]){
                for(ll j=0;A[j]!=A[i] && index<e;j++){
                    swap(B[j],B[index]);
                    index++;
                }
            }else{
                for(ll j=0;B[j]!=A[i] && index<e;j++){
                    swap(B[j],B[index]);
                    index++;
                }
            }
            for(ll j=start;A[index]==A[i];j++){
                swap(B[j],B[index]);
                index++;
            }
            break;
        }
    }
    cout<<"Yes"<<endl;
    for(ll i=0;i<N;i++) cout<<B[i]<<" ";
    cout<<endl;
    return 0;

    return 0;
}
