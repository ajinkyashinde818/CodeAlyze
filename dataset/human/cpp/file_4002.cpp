#include <iostream> // cin, cout, cerr, clog
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota, accumulate, inner_product
#include <cstdio> // printf, scanf
#include <climits> // INT_MIN, LLONG_MIN
#include <cmath> // long, trig, pow
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <stack> // stack
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <unordered_map> // hashed by keys
#include <unordered_set> // hashed by keys
#include <iomanip> // cout<<setprecision(n)
#include <functional> // std::function<void(int)>

#define rep(i,n) for(int i = 0; i < n; i++)
#define ENDL "\n"
#define print(i) std::cout << std::setprecision(10) << (i) << "\n"

#define int long long // at least int64 > 9*10^18
#define all(v) v.begin(), v.end()

template <typename T>
std::vector<T> dijkstra(int s,std::vector<std::vector<std::pair<int, T> > > & G){
	using namespace std;
  const T INF = numeric_limits<T>::max();
  using P = pair<T, int>;
  int n=G.size();
  vector<T> d(n,INF);
  vector<int> b(n,-1);
  priority_queue<P,vector<P>,greater<P> > q;
  d[s] = 0;
  q.emplace(d[s],s);
  while(!q.empty()){
    P p=q.top();q.pop();
    int v=p.second;
    if(d[v]<p.first) continue;
    for(auto& e:G[v]){
      int u=e.first;
      T c=e.second;
      if(d[u]>d[v]+c){
        d[u]=d[v]+c;
        b[u]=v;
        q.emplace(d[u],u);
      }
    }
  }
  return d;
}

struct Barrier
{
	int x,y,r;
	Barrier(int x, int y, int r) : x(x), y(y), r(r) {}
};

signed main() {
	std::vector<Barrier> barriers;
	{
		//start
		int x,y;
		std::cin >> x >> y;
		barriers.emplace_back(x,y,0);
	}
	{
		//end
		int x,y;
		std::cin >> x >> y;
		barriers.emplace_back(x,y,0);
	}
	int n;
	std::cin >> n;
	rep(i,n) {
		int x,y,r;
		std::cin >> x >> y >> r;
		barriers.emplace_back(x,y,r);
	}
	std::vector<std::vector<std::pair<int, double> > > from(n+2,std::vector<std::pair<int,double> >());
	for(int i=0;i<n+2;i++) {
		for(int j=0;j<n+2;j++) {
			if(i==j) continue;
			Barrier& a = barriers[i];
			Barrier& b = barriers[j];
			double zero = 0;
			double len = std::max(zero,std::sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))-a.r-b.r);
			from[i].emplace_back(j,len);
			from[j].emplace_back(i,len);
		}
	}
	std::vector<double> D = dijkstra<double>(0,from);
	print(D[1]);

	return 0;
}
