#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <sstream>
#include <map>
#include <vector>
#include <queue>
#include <iomanip>
#include <unordered_map>
using namespace std;
typedef long long ll;
ll ans, mx, sum,temp, mn = 1e14, flag,cnt;

string s[100],s2[100];
string t;
int main(){
	ll n,m;
	cin>>n>>m;
	for(ll i=0; i<n; i++){
		cin>>s[i];
	}
	for(ll i=0; i<m; i++){
		cin>>s2[i];
	}
	for(ll i=0; i<n; i++){
		for(ll j=0; j<n; j++){
			t+=s[i][j];
		}	
	}
	for(ll i=0; i<t.size(); i++){
		ll g=0,cnt=0;
		for(ll k=i; k<t.size(); k+=n){
			
			string r=t.substr(k,m);
			if(r==s2[g]){
				cnt++;
				g++;			
			}	
			if(cnt==m){
				cout<<"Yes";
				return 0;
			}
		}
	
		
	}
	cout<<"No";
}
