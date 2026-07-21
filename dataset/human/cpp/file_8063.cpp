#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
set<long long> b;
long long s=0,x,y;
int main(){
	int n,tmp;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>tmp;
		a.push_back(tmp);
		s+=tmp;
	}
	x=a[0];
	y=s-a[0];
	b.insert(abs(x-y));
	for (int i=1;i<n-1;i++){
		x+=a[i];
		y-=a[i];
		b.insert(abs(x-y));
	}
	cout<<*b.begin()<<endl;
	return 0;
}
