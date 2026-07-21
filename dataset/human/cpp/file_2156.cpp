#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;

long long s,m=1e9,p,a;

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a<0) p++;
		m = min(m,abs(a));
		s += abs(a);
	}
	//cout<<p<<" "<<s<<endl;
	if(p%2==0) cout<<s;
	else cout<<s-2*m;
 	return 0;
}
