#include<map>
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<queue>
#include<math.h>
#include<bitset>
#include<random>
using namespace std;
using ll = long long;
using lll = __int128_t;
typedef pair<ll,ll> P;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define rep0(i,n) REP(i,0ll,n)
#define rep1(i,n) REP(i,1ll,n+1)
const ll longinf=1ll<<60;
const int inf=(1<<30)-1;
const ll mod=1e9+7;

ll frac[200001];

void modcalc(){
      frac[0]=1;
      for(int i=1;i<=200000;i++){
            frac[i]=(frac[i-1]*i)%mod;
      }
}

int main(){
      modcalc();
      int n;
      cin>>n;
      string s;
      cin>>s;
      string t;
      for(int i=0;i<s.size();i++){
            if(i%2==0){
                  if(s[i]=='B'){
                        t.push_back('L');
                  }
                  else t.push_back('R');
            }
            else{
                  if(s[i]=='B'){
                        t.push_back('R');
                  }
                  else t.push_back('L');
            }
      }
      ll countl=0;
      ll countpair=0;
      ll ans=1;
      for(int i=0;i<t.size();i++){
            if(t[i]=='L'){
                  countl++;
            }
            else{
                  ans=(ans*countl)%mod;
                  countpair++;
                  countl--;
                  //cout<<ans<<endl;
            }
      }
      //cout<<t<<endl;
      if(countl==0){
            cout<<(ans*frac[countpair])%mod<<endl;
      }
      else{
            cout<<0<<endl;
      }
      return 0;
}
