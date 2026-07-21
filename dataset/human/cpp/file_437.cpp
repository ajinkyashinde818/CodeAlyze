#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
//const int MAX=;



int main(){
	int a,b,c,N;
	cin>>a>>b>>c>>N;
	int ans=0;
	rep(i,N/a+1)rep(j,N/b+1){
		int x=N-i*a-j*b;
		if(x<0)continue;
		if(x%c==0)ans++;
	}
	cout<<ans<<endl;
}
