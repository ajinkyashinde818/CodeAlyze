#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

typedef long long ll;
typedef vector <bool> v_bool;
typedef vector <ll> v_ll;
typedef vector <vector <ll> > vv_ll;
typedef vector < pair <ll,ll> > vp_ll;
typedef pair <ll,ll> p_ll;

bool TEST=false;
ll MOD = 1000000007;

void show(){if (TEST){cout << endl;}}
void show(string x){if (TEST){cout << x;}}
void show(string x,bool enter){
  if (TEST){if (enter) cout << "<#> " << x << endl;else cout << x;}
}
void show(ll x){if (TEST){cout << x;}}
void show(ll x,bool enter){
  if (TEST){if (enter) cout << "<#> " << x << endl;else cout << x;}
}
void show(p_ll p){
  if (TEST){cout << "{ ";show(p.first);cout << " ";show(p.second);cout << " }";}
}
void show(v_ll v){
  if (TEST){
    cout << "<begin> ";
    for (ll i=0;i<v.size();i++){show(v[i]); cout << " ";}cout <<"<end>"<< endl;
}}
void show(vv_ll v){
  if (TEST){
    cout << "//////////" << endl;
    for (ll i=0;i<v.size();i++){
      show(v[i]); cout << endl;
}}}
void show(vp_ll v){
  if (TEST){
    cout << "//////////" << endl;
    for (ll i=0;i<v.size();i++){
      show(v[i]); cout << endl;
}}}

ll mod(ll x){
  ll n=MOD;
  ll ret=x%n;
  if (ret<0)ret+=n;
  return ret;
}
void mod_self(ll &x){
  x=mod(x);
}
ll mod_inv(ll x){
  ll n=MOD;
  ll y = x,z = n-2, ret=1;
  y=mod(y);
  while (z>0){
    if(z%2==1) ret=mod(ret*y);
    y=mod(y*y);
    z/=2;
  }
  return ret;
}
ll mod_pow(ll x,ll a){
  ll y = x,z = a,ret=1;
  y=mod(y);
  if (z<0)z=-z;
  while (z>0){
    if(z%2==1) ret=mod(ret*y);
    y=mod(y*y);
    z/=2;
  }
  if (a<0) ret=mod_inv(ret);
  return ret;
}
v_ll mod_nck(ll n){
  v_ll nck(n+1,0);
  nck[0]=1;
  for (ll i=1;i<=n;i++){
    nck[i]=mod(nck[i-1]*(n+1-i));
    nck[i]=mod(nck[i]*mod_inv(i));
  }
  return nck;
}
v_ll mod_factorial(ll n){
  v_ll fct(n+1,0);
  fct[0]=1;
  for (ll i=1;i<=n;i++){
    fct[i]=mod(fct[i-1]*i);
  }
  return fct;
}

ll N,s,e,ans;
string S;
v_ll A;
int main(){
  cin >> N>> S;

  A.assign(2*N+10,0);
  if (S[0]!='B'){
    cout << 0 << endl;
    return 0;
  }
  ll t=0;
  for (ll i=0;i<2*N;i++){
    if ((S[i]=='B') && (t%2==0)){A[i]=0;t++;}
    else if ((S[i]!='B') && (t%2==1)){A[i]=0;t++;}
    else {A[i]=1;t--;}
  }
  //TEST=true;
  //show(A);
  ll x=0;
  for (ll i=0;i<2*N;i++){
    if (A[i]==0)x++;
  }
  if (x!=N){
    cout << 0 << endl;
    return 0;
  }
  s=0;e=0;
  ans=1;
  for (ll i=0;i<2*N;i++){
    if (A[i]==0)s++;
    else {
      if (s<=0){
        cout << 0 << endl;
        return 0;
      }
      ans*=s;ans%=MOD;s--;}
  }
  for (ll i=1;i<=N;i++){
    ans*=i;ans%=MOD;
  }
  cout << ans  << endl;
}
