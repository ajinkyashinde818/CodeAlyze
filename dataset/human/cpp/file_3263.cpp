#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
#include <deque>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
typedef long long ll;
//#define P pair<ll,ll>
#define FOR(I,A,B) for(int I = int(A); I < int(B); ++I)
#define FORR(I,A,B) for(int I = int((B)-1); I >= int(A); --I)
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define REV(x) (reverse(x.begin(),x.end())) //reverse
#define TO(x,t,f) ((x)?(t):(f))
#define CLR(mat) memset(mat, 0, sizeof(mat))
#define FILV(x,a) fill(x.begin(),x.end(),a)
#define FILA(ar,N,a) fill(ar,ar+N,a)
#define NEXTP(x) next_permutation(x.begin(),x.end())
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define pb push_back
#define pri(aa) cout<<(aa)<<endl
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
const ll INF=1e18+7;
const ll MOD=1e9+7;



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m=INF,ans=0;
	cin >> n;
	vector<ll> a(n);
	FOR(i,0,n){
		cin >> a[i];
		if(m>abs(a[i]))m=abs(a[i]);
		ans += abs(a[i]);
	}
	FOR(i,0,n-1){
		if(a[i]<0){
			a[i] *= -1;
			a[i+1] *= -1;
		}
	}
	if(a[n-1]<0){
		ans -= m*2;
	}
	cout << ans << endl;
}
