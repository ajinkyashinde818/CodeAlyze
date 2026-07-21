#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
 
using namespace std;
 
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define rep(i,n) REP(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(r) (r).begin(),(r).end()
#define rall(r) (r).rbegin(),(r).rend()
#define fi first
#define se second
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<ll, ll> pll;
 

 
const int INF = 1000000;
const double EPS = 1e-8;
const int mod = 1e9 + 7;
const ll LINF = 1e18;
const double PI = acos(-1);

struct Input
{
	int n;
	char c;
	char str[1024];
	string s;
	int nextInt(){
		scanf("%d", &n);
		return n;
	}
	char nextChar(){
		scanf("%c", &c);
		return c;
	}
	string next(){
		scanf("%s", str);
		return string(str);
	}
	string nextLine(){
		getline(cin, s);
		return s;
	}
};
Input in;

int dx[]={-1, 0, 1, 0};
int dy[]={0, -1, 0, 1};

string getBinary(char c){
	string ret;
	int p = 0;
	if(c >= '0' && c <= '9') p = c-'0';
	else p = 10 + c-'a';

	while(p > 0) ret += (char)('0'+p%2), p/=2;
	while(ret.size()<4) ret += '0';
	reverse(all(ret));
	return ret;
}

string calcs(string s){
	string ret;
	for(int i = 0; i < s.size(); i++) ret += getBinary(s[i]);
	return ret;
}

int calcr(string r){
	int ret = 0;
	reverse(all(r));
	int p = 1;

	rep(i, r.size()){
		ret += p * (r[i]-'0');
		p *= 2;
	}

	return ret;
}

string calcm(string m){
	double d = 0, p = 1.0;

	for(int i = 0; i < m.size(); i++){
		p /= 2.0;
		d += p * (m[i]-'0');
	}

	stringstream ss;
	string s;

	ss<<fixed << setprecision(7) << d;
	ss>>s;
	//cout<<" "<<s;

	if(s.size() < 2) return "0";
	int t = 0;
	for(int i = s.size()-1; i >= 0; i--){
		if(s[i]!='0') break;
		t++;
	}
	s = s.substr(2, ((int)s.size())-t-2);
	if(s.size()==0) return "0";
	return s;
}

int main(){
	int n = in.nextInt();
	while(n--){
		string s = in.next();
		s = calcs(s);
		string sign = s.substr(0, 1);
		string real = s.substr(1, 24);
		string imag = s.substr(25);

		int r = calcr(real);
		string m = calcm(imag);

		if(sign[0]=='1') cout<<'-';
		cout<<r<<"."<<m<<endl;
	}
}
