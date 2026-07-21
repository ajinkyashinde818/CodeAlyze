#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct UnionFind{
	int size;
	vector<int> parent;
	
	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++) parent[i] = i;
	}
	int root(int i){
		if(parent[i] == i) return i;
		return parent[i] = root(parent[i]);
	}
	bool same(int i, int j){
		return root(i) == root(j);
	}
	void unite(int i, int j){
		int root_i = root(i), root_j = root(j);
		if(root_i == root_j) return;
		parent[root_i] = root_j;
	}
};

int N;
int a[100005], b[100005];
int A[100005], B[100005];
UnionFind uf(100005);
vector<int> comp;

int main(void)
{
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];
	for(int i = 1; i <= N; i++) a[0] ^= a[i];
	for(int i = 1; i <= N; i++) cin >> b[i];
	
	for(int i = 0; i <= N; i++) A[i] = a[i], B[i] = b[i];
	sort(A, A+N+1), sort(B+1, B+N+1);
	
	int p = 0, dif = -1;
	for(int i = 1; i <= N; i++, p++){
		if(B[i] != A[p]){
			if(dif == -1){
				i--;
				dif = p;
			}
			else{
				cout << -1 << endl;
				return 0;
			}
		}
	}
	if(dif == -1) b[0] = A[N];
	else b[0] = A[dif];
	
	for(int i = 0; i <= N; i++) comp.push_back(a[i]);
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for(int i = 0; i <= N; i++){
		a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
		b[i] = lower_bound(comp.begin(), comp.end(), b[i]) - comp.begin();
	}
	
	int ans = 0;
	for(int i = 1; i <= N; i++){
		if(a[i] != b[i]) uf.unite(a[i], b[i]), ans++;
	}
	set<int> S;
	S.insert(uf.root(a[0]));
	for(int i = 1; i <= N; i++) if(a[i] != b[i]) S.insert(uf.root(a[i]));
	ans += S.size() - 1;
	
	cout << ans << endl;
	return 0;
}
