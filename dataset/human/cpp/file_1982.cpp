//dp状态:dp(i,j)表示离第i个结点距离为j的结点的个数 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll Abs(ll x){
	if(x<0) return -x;
	else return x;
}
int n;
ll in[100005];
priority_queue<ll> pq;
ll res;
int p;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>in[i];
		res+=Abs(in[i]);
	}
	p=0;
	for(int i=0;i<n;i++){
		if(in[i]<0){
			p=1-p;
			pq.push(in[i]);
		}
		else pq.push(-in[i]);
	}
	if(p==1) res+=2*pq.top();
	cout<<res<<endl;
	return 0;
}
