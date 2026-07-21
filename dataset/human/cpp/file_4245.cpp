#include <bits/stdc++.h>
using namespace std;
/***********************************************/
/* Dear online judge:
 * I've read the problem, and tried to solve it.
 * Even if you don't accept my solution, you should respect my effort.
 * I hope my code compiles and gets accepted.
 *  ___  __     _______    _______      
 * |\  \|\  \  |\  ___ \  |\  ___ \     
 * \ \  \/  /|_\ \   __/| \ \   __/|    
 *  \ \   ___  \\ \  \_|/__\ \  \_|/__  
 *   \ \  \\ \  \\ \  \_|\ \\ \  \_|\ \ 
 *    \ \__\\ \__\\ \_______\\ \_______\
 *     \|__| \|__| \|_______| \|_______|
 */
const long long mod = 1000000007;

struct DSU{
	vector<int> p,sz;
	DSU(int N){
		p.resize(N);
		sz.resize(N,1);
		for(int i = 0;i < N;i++)p[i] = i;
	}
	int par(int x){
		if(x == p[x])
			return x;
		return p[x] = par(p[x]);
	}
	bool mrg(int x,int y){
		x = par(x),y = par(y);
		if(x == y)
			return false;
		if(sz[x] < sz[y]){
			swap(x,y);
		}
		p[y] = p[x];
		sz[x] += sz[y];
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin>>N;
	vector<int> a(N),b(N),cpy;
	int Exor = 0;
	vector<int> all;
	for(int i = 0;i < N;i++) cin>>a[i],Exor ^= a[i],all.push_back(a[i]);
	all.push_back(Exor);
	
	for(int i = 0;i < N;i++) cin>>b[i];
	
	{ // determine NO
		cpy = b;
		sort(all.begin(),all.end());
		sort(cpy.begin(),cpy.end());
		bool can = true;
		for(int i = 0,j = 0;i < N && can;i++) {
			while(j < N + 1 && all[j] < cpy[i]) j++;
			if(j >= N + 1) can = false;
			if(j < N + 1 && all[j] > cpy[i]) can = false;
			j++;
		}
		if(!can) {
			cout<<"-1\n";
			return 0;
		}
	}
	
	all.clear();
	all.push_back(Exor);
	for(int i = 0;i < N;i++) {
		if(a[i] != b[i]) all.push_back(a[i]),all.push_back(b[i]);
	}
	
	sort(all.begin(),all.end());
	auto it = unique(all.begin(),all.end());
	all.erase(it,all.end());
	
	DSU dsu(all.size());
	int com = all.size();
	cerr<<com<<'\n';
	int diff = 0;
	for(int i = 0;i < N;i++) {
		if(a[i] == b[i]) continue;
		diff ++;
		auto x = lower_bound(all.begin(),all.end(),a[i]) - all.begin();
		auto y = lower_bound(all.begin(),all.end(),b[i]) - all.begin();
		assert(all[x] == a[i] && all[y] == b[i]);
		com -= dsu.mrg(x,y);
	}
	cerr<<com<<'\n';
	cout<<diff+(com-1)<<'\n';
	return 0;
}
