#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define vii vector<vi>

const double pi = 3.14159265358979323846264;
const int mod=1000000007;

int main(){
	 //cin.tie(0);
	//ios::sync_with_stdio(false);
	//std::cout << std::fixed;
	//std::cout << std::setprecision(12);
	//std::cout << std::defaultfloat;
	int n;
	cin>>n;
	vector<int> a(n);
	priority_queue<int> p;
	priority_queue<int> ng;
	LL ans=0;
	FOR(i,0,n){
		cin>>a[i];
		if(a[i]>=0){
			p.push(-a[i]);
			ans+=a[i];
		}else{
			ng.push(a[i]);
			ans+=-a[i];
		}
	}
	int sz=ng.size();
	if(sz%2==1){
		if(p.empty()){
			ans-=-ng.top()*2;
		}else if(-p.top()>-ng.top()){
			ans-=-ng.top()*2;
		}else{
			ans-=-p.top()*2;
		}
	}else{

	}
	cout<<ans;

	return 0;
}
