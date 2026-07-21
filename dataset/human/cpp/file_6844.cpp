#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+10;
const int mod = 1e9+7;
int a[N];
int b[N];
int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {
		cin>>b[i];
	}
	reverse(b+1,b+1+n);
	vector<int>p,q;
	int val=0,cnt=0;
	for(int i=1;i<=n;i++) {
		if(a[i]!=b[i]) continue;
		cnt++;
		p.push_back(i);
		val = b[i]; 
	}
	for(int i=1;i<=n;i++) {
		if(!cnt)break;
		if(a[i]==b[i]) {
			continue;
		}
		if(a[i]!=val&&b[i]!=val) {
			cnt--;
			q.push_back(i);
		}
	}
	if(cnt)  {
	cout<<"No"<<endl;
	return 0;
}
	for(int i=0;i<q.size();i++) {
		swap(b[p[i]],b[q[i]]);
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n;i++) {
		cout<<b[i]<<" ";
	}
	
	return 0;
}
