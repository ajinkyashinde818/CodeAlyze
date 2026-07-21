#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <math.h>
 
using namespace std;
typedef unsigned long ul;

int main() {
	long long n,c,x[100010],v[100010];
	long long r[100010],l[100010],ri[100010],li[100010];
	long long m = 0;
	cin>>n>>c;
	for(int i=0;i<n;i++){
		cin>>x[i]>>v[i];
	}

	r[0] = v[0] - x[0];
	ri[0] = 0;
	m = max(m, r[0]);
	for(int i=1;i<n;i++){
		r[i] = r[i-1] + v[i] - x[i] + x[i-1];
		ri[i] = r[i] > r[ri[i-1]] ? i : ri[i-1];
		m = max(m, r[i]);
	}
	l[n-1] = v[n-1] - c + x[n-1];
	li[n-1] = n-1;
	m = max(m, l[n-1]);
	for(int i=n-2;i>=0;i--){
		l[i] = l[i+1] + v[i] + x[i] - x[i+1];
		li[i] = l[i] > l[li[i+1]] ? i : li[i+1];
		m = max(m, l[i]);
	}

	for(int i=0;i<n-1;i++){
		m = max(m, r[i] - x[i] + l[li[i+1]]);
	}
	for(int i=n-1;i>0;i--){
		m = max(m, l[i] - c + x[i] + r[ri[i-1]]);
	}
	cout<<m<<endl;
}
