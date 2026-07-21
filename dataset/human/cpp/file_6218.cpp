#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

LL xs[100*1000];
LL as[100*1000];
LL bs[100*1000];
LL vs[100*1000];
int main() {
	LL N,C;
	cin >> N >> C;
	LL ret=0;
	LL s=0;
	LL pre=0;
	LL m=0;
	for(int i=0;i<N;i++){
		cin >> vs[i];
		cin >> xs[i];
		s+=xs[i];
		s-=abs(vs[i]-pre);
		pre=vs[i];
		ret=max(ret,s);
		m=max(m,s-vs[i]);
		as[i]=m;
	}
	s=0;
	pre=C;
	m=0;
	for(int i=N-1;i>=0;i--){
		s+=xs[i];
		s-=abs(vs[i]-pre);
		pre=vs[i];
		ret=max(ret,s);
		m=max(m,s-(C-vs[i]));
		bs[i]=m;
		if(i>0){
			ret=max(ret,as[i-1]+s);
		}
	}
	pre=0;
	s=0;
	for(int i=0;i<N-1;i++){
		s+=xs[i];
		s-=abs(vs[i]-pre);
		pre=vs[i];
		ret=max(ret,bs[i+1]+s);
	}
	cout << ret << endl;

	return 0;
}
