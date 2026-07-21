#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
// *st.find_by_order(index), 0-based
// order_of_key(e)

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int N; cin>>N;
	vector<int> a(N), b(N);
	for (int i=0; i<N; i++)
		cin>>a[i];
	for (int i=0; i<N; i++)
		cin>>b[i];
	reverse(b.begin(),b.end());
	for (int i=0; i<N; i++) {
		if(a[i]!=b[i]) continue;
		bool ok=false;
		for (int j=0; j<N; j++) {
			if(i==j) continue;
			if(a[i]!=b[j] && a[j]!=b[i]) {
				swap(b[i],b[j]); ok=true; break;
			}
		}
		if(!ok) {
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
	for (auto x : b)
		cout<<x<<" ";
	cout<<"\n";
	return 0;
}
