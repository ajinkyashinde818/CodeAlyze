#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 3e18;
double Pi = 3.1415926535897932384626;
 
//vector<ll> G[550010];
//vector<P> tree[500010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop
 
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";
//ll bit[500005];
//↓,→,↑,←
 
 
#define p(x) cout<<x<<"\n";
#define el cout<<endl;
#define pe(x) cout<<(x)<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)(); 
 
 
ll mod = 1000000007;
/*
2000000011 is prime
2000000033 is prime
*/

ll rui(ll number1,ll number2){
 
    if(number2 == 0){
        return 1;
    }else{
        ll number3 = rui(number1,number2 / 2);
        number3 *= number3;
        number3 %= mod;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod;
        }
        return number3;
    }
}
ll gcd(ll number1,ll number2){
 
    if(number1 > number2){
        swap(number1,number2);
    }
    if(number1 == 0 || number1 == number2){
        return number2;
    }else{
        return gcd(number2 % number1,number1);
    }
}
void YES(bool condition){
 
    if(condition){
        p("YES");
    }else{
        p("NO");
    }
    return;
}
void Yes(bool condition){
 
    if(condition){
        p("Yes");
    }else{
        p("No");
    }
    return;
}


ll fact[800005],rfact[800005];

void c3_init(){
    fact[0] = rfact[0] = 1;
    for(ll i=1; i<=800000; i++){
        fact[i] = (fact[i-1]*i) % mod;
    }
    rfact[800000] = rui(fact[800000],mod - 2);
    for(ll i=800000; i>=1; i--){
       rfact[i-1] = rfact[i] * i;
       rfact[i-1] %= mod;
    }
    return;}
ll c3(ll n,ll r){
    return (((fact[n] * rfact[r]) % mod) * rfact[n-r]) % mod;}

 
ll n,m,num,sum,a,b,c,d,e,g,h,w,i,j,q,r;
ll k,ans;
ll x[500005],y[500005],z[500005];
char s[500005];
bool dp[500005];



int main(){
    cin >> n;
    cin >> s;
    c3_init();
    int state = 1;
    for(i=0;i<2*n;i++){
        if(state == 1 && s[i] == 'B'){
            dp[i] = true;
        }
        if(state == 2 && s[i] == 'W'){
            dp[i] = true;
        }
        if(s[i] == 'W'){
            state = 1;
        }else{
            state = 2;
        }
        //pe(dp[i]);
    }
    if(state == 2)dp[2*n] = true;
    //el;
    for(i=0;i<2*n;i++){
        if(dp[i]){
            dp[i] = false;
            y[i] = 3;
        }else{
            if(dp[i+1]){
                dp[i+1] = false;
                y[i] = 4;
            }else{
                dp[i+1] = true;
                y[i] = 4;
            }
        }
        //pe(y[i]);
    }
    ll num = 0;
    ans = 1;
    for(i=0;i<2*n;i++){
        if(y[i] == 3){
            num++;
        }else{
            if(num <= 0)ans = 0;
            ans *= num;
            ans %= mod;
            num--;
        }
    }
    if(num != 0){
        ans = 0;
    }
    ans *= (fact[n]) % mod;
    ans %= mod;
    p(ans);
    
    return 0;
}
