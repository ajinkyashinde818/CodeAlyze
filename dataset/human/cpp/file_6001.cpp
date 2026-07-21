#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int n,v[N];
long long c,cs[N],x[N],cs1[N];
int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d%lld",&n,&c);
	for(int i = 0;i < n;i++)scanf("%lld%d",x + i,v + i);
	long long last = 0,bad = 0,ans = 0,sum = 0;
	for(int i = 0;i < n;i++){
		bad = x[i];
		last = x[i];
		sum+=v[i];
		ans = max(ans,sum - bad);
		cs[i] = sum - bad - bad;
		cs1[i] = sum - bad;
 	}
 	for(int i = 1;i < n;i++){
 		cs[i] = max(cs[i],cs[i - 1]);
 		cs1[i] = max(cs1[i],cs1[i - 1]); 
 	}
 	last = c;bad = 0;sum = 0;
 	for(int i = n - 1;i + 1;i--){
 		bad = last - x[i];
 		sum+=v[i];
		ans = max(ans,sum - bad);
 		ans = max(ans,sum - bad + (i ? cs[i - 1] : 0));	
 		ans = max(ans,sum - bad - bad + (i ? cs1[i - 1] : 0));
 	}
 	cout << ans << endl;
}
