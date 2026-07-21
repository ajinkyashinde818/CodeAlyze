#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <math.h>
#include <stack>
using namespace std;
typedef long long ll;

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n,m; cin >> n >> m;
	vector<bool> used(n,0);
	stack<int> st;
	for(int i=0;i<m;i++){
		int s; cin >> s;
		s--;
		st.push(s);
	}
	while(st.size()){
		int p=st.top();
		if(!used[p]){
			printf("%d\n",p+1);
			used[p]=1;
		}
		st.pop();
	}
	for(int i=0;i<n;i++){
		if(!used[i]){
			printf("%d\n",i+1 );
		}
	}
}
