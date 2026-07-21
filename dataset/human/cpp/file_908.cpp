#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int res;

int main() {
	int r,g,b,n,m,i,j,k;
	cin>>r>>g>>b>>n;
	m = n;
	for(i=0;i<=n/r;i++){
		m = n;
		m -= i*r;
		for(j=0;j<=m/g;j++){
			m -= j*g;
			if(m%b==0) res++;
			m += j*g;
		}
	}
	cout<<res;
	return 0;
}
