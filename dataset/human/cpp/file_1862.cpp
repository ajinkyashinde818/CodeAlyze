#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>

using namespace std;

#define REP(i,n) for(int i=0;i<int(n);i++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
typedef long long ll;
typedef pair<int,int> P;

int a[200010],c[200010];

int main(void){
	int i;

	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n,m;
	cin >> n >> m;

	for(i=1;i<=n;i++) a[i]=i;
	stack<int>st;
	for(i=1;i<=m;i++){
		int x;
		cin >> x;
		st.push(x);
		a[x]=-1;
	}

	while(!st.empty()){
		int p=st.top();
		st.pop();
		if(c[p]==0){
			cout << p << endl;
			c[p]=1;
		}
	}

	for(i=1;i<=n;i++) if(a[i]!=-1) cout << a[i] << endl;

	return 0;
}
