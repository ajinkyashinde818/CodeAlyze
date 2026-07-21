#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <typeinfo>
#include <random>
#include <vector>
 
using namespace std;
typedef long long ll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;
 
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define all(a) (a).begin(), (a).end()

int main()
{
	int n;
	cin>>n;
	vi a(n);
	int cnt=0;
	rep(i,n){
		cin>>a.at(i);
		if(a.at(i)<=0){
			cnt++;
		}
	}
	ll ans=0;
	if(cnt%2==0){
		rep(i,n){
			ans+=abs(a.at(i));
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(all(a));
	vi ng,ps;
	ng.push_back(0);
	ps.push_back(0);
	rep(i,n){
		if(a.at(i)<0){
			ng.push_back(-1*a.at(i));
		}else{
			ps.push_back(a.at(i));
		}
	}
	rep(i,ng.size()){
		if(i!=ng.size()-1){
			ans+=ng.at(i);
		}
	}
	rep(i,ps.size()){
		if(i!=1){
			ans+=ps.at(i);
		}
	}
	if(ps.size()==1){
		ans-=ng.at(ng.size()-1);
	}else{
		if(ng.at(ng.size()-1)>ps.at(1)){
			ans+=ng.at(ng.size()-1);
			ans-=ps.at(1);
		}else{
			ans-=ng.at(ng.size()-1);
			ans+=ps.at(1);
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
