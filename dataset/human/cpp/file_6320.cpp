#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>
#include<complex>

using namespace std;

#define ll long long
#define ld long double
#define EPS 1e-9
#define INF 1e9
#define LINF (ll)INF*INF
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;
typedef vector<pii> vp;
typedef vector<vi> vvi;

int gcd(int a, int b){if(b==0) return a;return gcd(b,a%b);}
int lcm(int a, int b){return a/gcd(a,b)*b;}


signed main(void) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1;
    int cnt = 0;
    int sum = 0;
    rep(i,s.size()){
        s[i] = char(s[i] == 'B');
        //cout << i << " " << s[i] << " " << cnt << " " << sum << " " << ans << endl;
        if(sum == n || cnt == n){
            if(s[i] != cnt%2){
                cout << 0 << endl;
                return 0;
            }
            ans *= cnt;
            ans %= MOD;
            cnt--;
        }else if(cnt == 0){
            cnt++;
            sum++;
            if(s[i] != cnt%2){
                cout << 0 << endl;
                return 0;
            }
        }else{
            if(s[i] == cnt%2){//へる
                ans *= cnt;
                ans %= MOD;
                cnt--;
            }else{
                cnt++;
                sum++;
            }
        }
    }
    loop(i,1,n+1){
        ans *= i;
        ans %= MOD;
    }
    if(sum == n)cout << ans << endl;
    else cout << 0 << endl;
}
