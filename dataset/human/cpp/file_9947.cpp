#include "bits/stdc++.h"

using namespace std;
using ll=long long;
using ull=unsigned long long;

typedef pair<int,int>Pi;
typedef pair<long long,long long>P;
typedef pair<long long,P>PP;
typedef pair<P,P>PPP;

const long long MOD=1e9+7;
const long long INF=5e18;
const int di[4]={1,0,-1,0};
const int dj[4]={0,1,0,-1};

#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()

int n;
ll cnt[30],ans;
string s;

void input(){
	cin>>n>>s;
	return;
}

void solve(){
	for(int i=0;i<26;i++){
		cnt[i]=0;
	}
	for(int i=0;i<n;i++){
		cnt[s[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		cnt[i]++;
	}
	ans=1;
	for(int i=0;i<26;i++){
		ans*=cnt[i];
		ans%=MOD;
	}
	cout<<((ans+MOD)-1)%MOD<<endl;
	return;
}

int main(){
	input();
	solve();
	return 0;
}
