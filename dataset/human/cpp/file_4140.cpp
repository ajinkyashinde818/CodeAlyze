//#pragma GCC optimize ("-O3")
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <cstdio>
#include <string>
#include <bitset>
#include <list>
#include <set>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <functional>
#include <queue>
#include <regex>
#include <cassert>
#include <map>
#include <type_traits>
#include <array>
#include <cassert>
#include <typeinfo>
#include <time.h>
#include <iomanip>
#include <random>
#include <sstream>
#ifdef _MSC_VER
#include <intrin.h>
#define popcnt __popcnt64
//#  define __builtin_popcount __popcnt
#else
#define popcnt __builtin_popcountll
#endif
//#include "boost/variant.hpp"



using namespace std;

typedef long long ll;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

#define rep(i, N, M) for(ll i=N, i##_len=(M); i<i##_len; ++i)
#define rep_skip(i, N, M, ...) for(ll i=N, i##_len=(M); i<i##_len; i+=(skip))
#define rrep(i, N, M)  for(ll i=(M)-1, i##_len=(N-1); i>i##_len; --i)
#define pb push_back
#define fir first
#define sec second
#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define perm(c) sort(all(c));for(bool c##perm=1;c##perm;c##perm=next_permutation(all(c))) //perm(c){write(c)} writes all permutation of c 

typedef pair<double, double> pd;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
template<typename T>
using pq_greater = priority_queue<T, vector<T>, greater<T>>;
struct Point { ll x; ll y; };
using vpt = vector<Point>;

template<int n>
struct tll_impl {
	using type = decltype(tuple_cat(tuple<ll>(), declval<typename tll_impl<n - 1>::type>()));
};
template<>
struct tll_impl<1> {
	using type = tuple<ll>;
};
template<int n>
using tll = typename tll_impl<n>::type;

template<class T>
constexpr ll SZ(T& v) { return static_cast<ll>(v.size()); };

template<int n, typename T>
struct vec_t_impl {
	using type = vector<typename vec_t_impl<n-1,T>::type>;
};
template<typename T>
struct vec_t_impl<1,T> {
	using type = vector<T>;
};
template<int n, typename T>
using vec_t = typename vec_t_impl<n, T>::type;
// check 
static_assert(is_same<vec_t<3,ll>, vector<vector<vector<ll>>>>::value, "");

// decompose vector into basetype and dimension.
template<typename T> 
struct vec_dec {
	static constexpr int dim = 0;
	using type  = T;
};
template<typename T>
struct vec_dec<vector<T>> {
	static constexpr int dim = vec_dec<T>::dim+1;
	using type  = typename vec_dec<T>::type;
};
static_assert(is_same<typename vec_dec<vec_t<3, ll>>::type, ll>::value, "");
static_assert(vec_dec<vec_t<3, ll>>::dim == 3, "");

template<typename T = ll>
vector<T> makev(size_t a) { return vector<T>(a); }

template<typename T = ll, typename... Ts>
auto makev(size_t a, Ts... ts) {
	return vector<decltype(makev<T>(ts...))>(a, makev<T>(ts...));
}
// ex:  auto dp =  makev<ll>(4,5) => vector<vector<ll>> dp(4,vector<ll>(5));

// check if T is vector
template < typename T >
struct is_vector : std::false_type {};

template < typename T >
struct is_vector<vector<T>> : std::true_type {};
static_assert(is_vector<vector<ll>>::value == true && is_vector<ll>::value == false, "");

// check if T is vector
template < typename T>
struct is_pair : std::false_type {};

template < typename T, typename S >
struct is_pair<pair<T, S>> : std::true_type {};
static_assert(is_pair<pll>::value == true && is_pair<ll>::value == false, "");

template<typename T, typename V, typename enable_if<!is_vector<T>::value, nullptr_t>::type = nullptr>
void fill_v(T& t, const V& v) { t = v; }

template<typename T, typename V, typename enable_if<is_vector<T>::value, nullptr_t>::type = nullptr>
void fill_v(T& t, const V& v) {
	for (auto &&x : t)
		fill_v(x, v);
}
// ex:  fill_v(dp, INF);

template<typename T, typename enable_if < !is_vector<T>::value && !is_pair<T>::value, nullptr_t > ::type = nullptr >
void read(T& x) {	cin >> x;}

template<typename T, typename enable_if<is_pair<T>::value, nullptr_t>::type = nullptr>
void read(T& x) { read(x.first); read(x.second); }

template<typename T, typename enable_if<is_vector<T>::value, nullptr_t>::type = nullptr>
void read(T& x) { rep(i,0,x.size()) read(x[i]); }

template<>
void read(Point& p) { cin >> p.x >> p.y; }

template<typename T, typename Delim_t = string, typename enable_if<!is_vector<T>::value, nullptr_t>::type = nullptr>
void write(T& x, Delim_t delim = " ") { cout << x << delim; }

template<typename T, typename Delim_t = string, typename enable_if<is_vector<T>::value, nullptr_t>::type = nullptr>
void write(T& x, Delim_t delim = " ") { rep(i, 0, x.size()) write(x[i], (i == (x.size() - 1) ? "" : delim)); cout << '\n'; }



template<typename T> void chmin(T &a, T b) {
	if (a > b) a = b;
}
template<typename T> void chmax(T &a, T b) {
	if (a < b) a = b;
}

vll seq(ll i, ll j) {
	vll res(j - i);
	rep(k, i, j) res[k] = i + k;
	return res;
}

constexpr ll POW_0(ll x, ll y) {
	if (y == 0)return 1;
	if (y == 1)return x ;
	if (y == 2)return x * x ;
	if (y % 2 == 0)return POW_0(POW_0(x, y / 2), 2LL);
	return ((POW_0(POW_0(x, y / 2), 2LL)) * (x)) ;
}

constexpr ll POW(ll x, ll y, ll mod = 0) {
	if (mod == 0)return POW_0(x, y);
	if (y == 0)return 1;
	if (y == 1)return x % mod;
	if (y == 2)return x * x % mod;
	if (y % 2 == 0)return POW(POW(x, y / 2, mod), 2LL, mod) % mod;
	return ((POW(POW(x, y / 2, mod), 2LL, mod)) * (x % mod)) % mod;
}

template<
	typename Inputs,
	typename Functor,
	typename T = typename Inputs::value_type>
	void sort_by(Inputs& inputs, Functor f) {
	std::sort(std::begin(inputs), std::end(inputs),
		[&f](const T& lhs, const T& rhs) { return f(lhs) < f(rhs); });
}

template<
	typename Inputs,
	typename Functor,
	typename T = typename Inputs::value_type>
	void stable_sort_by(Inputs& inputs, Functor f) {
	std::stable_sort(std::begin(inputs), std::end(inputs),
		[&f](const T& lhs, const T& rhs) { return f(lhs) < f(rhs); });
}

template<typename Inputs>
void sort_uniq(Inputs& inputs) {
	sort(all(inputs));
	inputs.erase(unique(all(inputs)), inputs.end());
}

vector<string> split(const string& s, char delim) {
	vector<string> elems;
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		if (!item.empty()) {
			elems.push_back(item);
		}
	}
	return elems;
}

template<class T>
map<T,ll> inv_map(vector<T>& x) {
	map<T, ll> res;
	rep(i, 0, x.size()) {
		res[x[i]] = i;
	}
	return res;
}





struct UnionFind {
	vector<ll> data;
	vll querySize_;
	set<ll> roots;
	UnionFind(ll size) : data(size, -1), querySize_(size, 0) {
		rep(i, 0, size) roots.insert(i);
	}

	ll unite(ll x, ll y) {
		// return: root
		x = get_root(x); y = get_root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
			querySize_[x] += querySize_[y] + 1;
			roots.erase(y);
			return x;
		}
		else {
			querySize_[x]++;
			return x;
		}
	}
	bool is_same(ll x, ll y) {
		// check whether x and y are connected
		return get_root(x) == get_root(y);
	}
	ll get_root(ll x) {
		// get root
		return data[x] < 0 ? x : data[x] = get_root(data[x]);
	}
	ll size(ll x) {
		return -data[get_root(x)];
	}
	ll  query_size(ll x) {
		return querySize_[get_root(x)];
	}
	const set<ll>& get_roots() {
		return roots;
	}
	void initialize() {
		for (auto& i : data) {
			i = -1;
		}
	}
};




template<class cost_t>
struct Edge_Base
{
	ll from;
	ll to;
	cost_t cost;
	Edge_Base reverse() const { return Edge_Base{ to, from , cost }; }
	Edge_Base(ll from , ll to, cost_t cost=1) : from(from),to(to),cost(cost){};
	Edge_Base(pll e) :from(e.first), to(e.second), cost(1) { }
	Edge_Base() :from(0), to(0), cost(0){ };
	bool operator<  (const Edge_Base& e) const {	return cost < e.cost; }
	bool operator>  (const Edge_Base& e) const {	return cost > e.cost; }
	bool operator== (const Edge_Base& e) const { return cost == e.cost && from == e.from && to == e.to; }
};
using Edge = Edge_Base<ll>;

template<class EdgeType, class EdgeContainerType>
struct Edge_Itr_Base {
	constexpr Edge_Itr_Base() :index(), edges(nullptr) {}
	constexpr Edge_Itr_Base(ll index, EdgeContainerType& edges_) :index(index), edges(&edges_) {}
	constexpr Edge_Itr_Base& operator++() { ++index; return *this; }
	constexpr bool operator==(const Edge_Itr_Base& rhs) const { return index == rhs.index; }
	constexpr bool operator!=(const Edge_Itr_Base& rhs) const { return index != rhs.index; }
	constexpr EdgeType* operator->() const { return &(*edges)[index]; }
	constexpr EdgeType& operator*() const { return (*edges)[index]; }
	constexpr Edge_Itr_Base& operator+=(ll n) { index += n; return *this; }
	ll index;
	EdgeContainerType* edges;
};



auto nullAction = [](const auto&) {};

template<class cost_t>
struct Graph_Base {
	using Edge = Edge_Base<cost_t>;
	using Edge_Itr = Edge_Itr_Base<Edge_Base<cost_t>, vector<Edge_Base<cost_t>>>;
	using Edge_CItr = Edge_Itr_Base<const Edge_Base<cost_t>, const vector<Edge_Base<cost_t>>>;

	ll nodeSize;
	vector<Edge> edges;
	vector<vector<Edge_Itr>> out_edges;
	vector<vector<Edge_Itr>> in_edges;
	enum Dir{dir, undir};
	Graph_Base(ll nodeSize, const vector<Edge>& edges_ = vector<Edge>(), Dir dirct= dir)
		: nodeSize(nodeSize), out_edges(nodeSize), in_edges(nodeSize){
		if (dirct == undir) {
			for (const Edge& e : edges_) push_undir(e);
		}
		else {
			for (const Edge& e : edges_) push(e);
		}
	}
	Graph_Base(ll nodeSize, vector<pll> edges_, Dir dirct = dir)
		: nodeSize(nodeSize), out_edges(nodeSize), in_edges(nodeSize){
		if (dirct == undir) {
			for (const pll& e : edges_) push_undir(Edge(e));
		}
		else {
			for (const pll& e : edges_) push(Edge(e));
		}
	}
	Graph_Base(vvll ajacency_matrix, ll default_value) 
		: nodeSize(ajacency_matrix.size()), out_edges(nodeSize), in_edges(nodeSize){
		ll n = ajacency_matrix.size();
		rep(i, 0, n)rep(j, 0, n) {
			if (ajacency_matrix[i][j] != default_value)
				push(Edge(i, j, ajacency_matrix[i][j]));
		}
	}
	
	Edge& operator[](ll ind) { return this->edges[ind]; } 
	const Edge& operator[](ll ind) const{ return this->edges[ind]; }
	vector<Edge_Itr>& out(ll ind){ return this->out_edges[ind]; }
	const vector<Edge_Itr>& out(ll ind) const { return this->out_edges[ind]; }
	vector<Edge_Itr>& in(ll ind){ return this->in_edges[ind]; }
	const vector<Edge_Itr>& in(ll ind) const{ return this->in_edges[ind]; }
	Edge_Itr begin() { return Edge_Itr(0, edges); }
	Edge_Itr end() { return Edge_Itr(edges.size(), edges); }
	Edge_CItr begin() const { return Edge_CItr(0, edges); }
	Edge_CItr end() const { return Edge_CItr(edges.size(), edges); }

	ll size() const { return nodeSize; }
	ll sizeEdges() const { return edges.size(); }

	void push(const Edge& edge){
		assert(max(edge.from, edge.to) < nodeSize);
		edges.emplace_back(edge);
		out_edges[edge.from].emplace_back(Edge_Itr(edges.size()-1,edges));
		in_edges[edge.to].emplace_back(Edge_Itr(edges.size() - 1, edges));
	}
	void push(const Edge& edge, Graph_Base::Dir dir) {
		if (dir == Dir::undir)
			push_undir(edge);
		else
			push(edge);
	}
	void push_undir(const Edge& edge) {
		push(edge); push(edge.reverse());
	}
	void push(vector<Edge> edges) {
		for (const Edge& e : edges) {
			push(e);
		}
	}
	vvll adjacency_matrix() const {
		vvll d(size(), vll(size()));
		for (auto& e : edges) {
			d[e.from][e.to] = e.cost;
		}
		return d;
	}

	vll get_topologically_sorted_nodes() const
	{
		// graph needs to be represented by adjacent list.
		// complexity: O( node size + edge size)
		ll nodeSize = this->size();

		// find root
		vll roots;
		vll inDegree(nodeSize);
		rep(i, 0, nodeSize)
		{
			for (auto& sibling : this->out(i)) {
				inDegree[sibling->to]++;
			}
		}
		rep(i, 0, nodeSize) {
			if (inDegree[i] == 0) {
				roots.push_back(i);
			}
		}

		stack<ll> parents;
		for (ll i : roots)
			parents.push(i);

		vll sortedNodes;
		while (!parents.empty()) {
			ll parent = parents.top();
			parents.pop();
			sortedNodes.push_back(parent);
			for (auto& sibling : this->out(parent)) {
				inDegree[sibling->to]--;
				if (inDegree[sibling->to] == 0) {
					parents.push(sibling->to);
				}
			}
		}
		return sortedNodes;
	}

	void topological_sort() {
		vll sorted = get_topologically_sorted_nodes();
		vll new_ind(sorted.size());
		vector<Edge> new_edges;
		rep(i, 0, sorted.size()) {
			new_ind[sorted[i]] = i;
		}
		for (Edge& e : edges) {
			new_edges.emplace_back(Edge{ new_ind[e.from], new_ind[e.to],e.cost });
		}
		*this = Graph_Base(this->size(), new_edges);
	}
	ll diameter() const
	{
		// require : graph is tree
		// calculate the diameter ( longest path length ) in O(N)
		vll dp(size(), -1);
		ll m = 0; ll ind;
		function<void(ll)> dfs = [&](ll x) {
			for (auto& e : out(x)) {
				ll nextnode = e->to;
				if (dp[nextnode] == -1) {
					dp[nextnode] = dp[x] + 1;
					if (dp[nextnode] > m) {
						m = dp[nextnode];  ind = nextnode;
					}
					dfs(nextnode);
				}
			}
		};
		dp[0] = 0; ind = 0;
		dfs(0);
		ll first = ind;
		fill_v(dp, -1);
		dp[first] = 0;
		dfs(first);
		return m;
		// remark two end points of diameter are 'first' and 'ind';
	}

	vll leaves() const {
		vll res;
		rep(i, 0, nodeSize) {
			if (out(i).size() <= 1)
				res.push_back(i);
		}
		return res;
	}
	template<class T, class S = decltype(nullAction)>
	void dfs(ll startNode, T before_act, S after_act = nullAction) const
	{
		// Impliment func: void(const Edge&) representing what this should do, when target node moves from visited node (e.from) to unvisited node (e.to).
		const auto& graph = *this;
		vb visited(graph.size());
		auto dfs_impl = [&](auto dfs_impl, ll startNode)-> void {
			visited[startNode] = 1;
			for (auto& e : graph.out(startNode)) {
				if (visited[e->to])
					continue;
				before_act(*e);
				dfs_impl(dfs_impl, e->to);
				after_act(*e);
			}
		};
		dfs_impl(dfs_impl, startNode);

	};

	template<class T, class S = decltype(nullAction)>
	void dfs_node(ll startNode, T before_act, S after_act = nullAction) const
	{
		// Impliment func: void(ll node_ind) representing what this should do, when target node moves from visited node to unvisited node (node_ind).
		const auto& graph = *this;
		vb visited(graph.size());
		auto dfs_impl = [&](auto dfs_impl, ll startNode)-> void {
			before_act(startNode);
			visited[startNode] = 1;
			for (auto& e : graph.out(startNode)) {
				if (visited[e->to])
					continue;
				dfs_impl(dfs_impl, e->to);
			}
			after_act(startNode);
		};
		dfs_impl(dfs_impl, startNode);
	};

	template<class T, class S = decltype(nullAction)>
	void bfs(ll startNode, T before_act, S after_act = nullAction) const
	{
		const auto& graph = *this;
		vb visited(graph.size());
		auto bfs_impl = [&](ll startNode) {
			//if (visited[startNode] != 0) return;
			visited[startNode] = 1;
			queue<Edge> toVisit;
			for (auto& e : graph.out(startNode))
				toVisit.push(*e);
			while (toVisit.size()) {
				auto next = toVisit.front(); toVisit.pop();
				if (visited[next.to])
					continue;
				visited[next.to] = 1;
				before_act(next);
				for (auto& e : graph.out(next.to)) {
					if (!visited[e->to])
						toVisit.push(*e);
				}
				after_act(next);
			}
		};
		bfs_impl(startNode);
	};
	
	vector<cost_t> dijkstra(ll start) const {
		vector<cost_t> fromList;
		return dijkstra(start, fromList);
	}

	vector<cost_t> dijkstra(ll start, vector<cost_t>& from_list) const {
		// graph: weighted directed graph of adjacent representation
		// start: index of start point
		// return1: minimum path length from start
		// complexity : E*log(V)
		const auto& graph = *this;
		ll node_size = graph.size();
		vector<cost_t> dist(node_size, INF);
		from_list.resize(node_size);
		fill_v(from_list, -1);
		dist[start] = 0;
		pq_greater<pair<cost_t, pll>> pq;
		pq.push({ 0, {start, start} });
		while (!pq.empty()) {
			auto node = pq.top(); pq.pop();
			// if not shortest path fixed, fix
			ll from = node.second.first;
			ll to = node.second.second;
			if (from_list[to] != -1)
				continue;
			from_list[to] = from;

			for (auto& edge : graph.out(to)) {
				ll adj = edge->to;
				cost_t cost = dist[to] + edge->cost;
				if (dist[adj] > cost) {
					dist[adj] = min(dist[adj], cost);
					pq.push({ cost ,{to, adj} });
				}
			}
		}
		return dist;
	}

	vll euler_tour(ll start) const
	{
		vll res;
		res.push_back(start);
		dfs(start, [&](const Edge& e) {
			res.push_back(e.to);
			}, [&](const Edge& e) {
				res.push_back(e.from);
			});
		return res;
	}

	Graph_Base kruskal(Graph_Base::Dir = Dir::undir) const
	{
		//returns minimal spanning tree
		Graph_Base res(nodeSize);
		vpll sortedEdges;
		rep(i, 0, edges.size()) {
			sortedEdges.push_back({ edges[i].cost, i });
		}
		sort(all(sortedEdges));
		UnionFind uf(nodeSize);
		rep(i, 0, sortedEdges.size()) {
			ll cost, eInd;
			tie(cost, eInd) = sortedEdges[i];
			ll from = (*this)[eInd].from; ll to = (*this)[eInd].to;
			if (!uf.is_same(from, to)) {
				res.push((*this)[eInd], dir);
			}
			uf.unite(from, to);
		}
		return res;
	}

	vvll warshall_floyd() const {
		// O(|V|^3)
		const Graph_Base& g = *this;
		ll n = g.size();
		vvll d = g.adjacency_matrix();
		rep(k, 0, n)rep(i, 0, n)rep(j, 0, n) {
			if (d[i][j] > d[i][k] + d[k][j])
				d[i][j] = d[i][k] + d[k][j];
		}
		return d;
	}

	vll bellman_ford(ll start, ll negative_closed_loop_value = -INF) const {
		vll from_list;
		return bellman_ford(start, from_list, negative_closed_loop_value);
	}

	vll bellman_ford(ll start, vll& from_list, ll negative_closed_loop_value = -INF) const {
		// O(|E| * |V|)
		const Graph_Base& g = *this;
		vll dist(g.size(), INF);
		dist[start] = 0;
		from_list.resize(g.size());
		rep(i, 0, g.size()) {
			for(const Edge& e: g){
				if (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost) {
					dist[e.to] = dist[e.from] + e.cost;
					from_list[e.to] = e.from;
					if (i == g.size() - 1 && dist[e.to] != INF) {
						// check negative closed loop
						dist[e.to] = negative_closed_loop_value;
					}
				}
			}
		}
		// propagate negative path
		rep(i, 0, g.size()) {
			rep(j, 0, g.edges.size()) {
				auto& e = g.edges[j];
				if (dist[e.from] == negative_closed_loop_value && dist[e.from] != INF)
					dist[e.to] = negative_closed_loop_value;
			}
		}
		return dist;
	}

	bool is_bipartite() const {
		vll even(size(),-1);
		even[0] = 0;
		bool ok = true;
		dfs_node(0,
			[&](ll node) {
				for (auto& e : out(node)) {
					if (even[e->to] != -1 ) {
						if (even[e->from] == even[e->to]) {
							ok = false;
							break;
						}
					}
					else {
						even[e->to] = !even[e->from];
					}
				}
			});
		return ok;
	}
};

using Graph = Graph_Base<ll>;

vll shortest_path_generator(const vll& from_list, ll start, ll goal) {
	// usage : vll path =  shortest_path(dijkstra(g,s).second, s, g);
	vll path;
	path.emplace_back(goal);
	while (true) {
		ll from = from_list[goal];
		path.emplace_back(from);
		if (from == start) {
			break;
		}
		goal = from;
	}
	reverse(all(path));
	return path;
}

class FordFulkerson {
private:
	vb usedNode;
	using Edge = Edge_Base<ll>;
public:
	struct RevEdge { ll from, to, cap, rev; };

	FordFulkerson(Graph graph) 
		:usedNode(graph.size()), G(vec_t<2,RevEdge>(graph.size()))
	{
		rep(i, 0, graph.size()) {
			for (auto& e : graph.out(i)) {
				add_revedge(*e);
			}
		}

	}
	vec_t<2, RevEdge> G;
	void add_revedge(const Edge& e) {
		G[e.from].push_back(RevEdge{ e.from, e.to ,e.cost, SZ(G[e.to]) });
		G[e.to].push_back(RevEdge{ e.to, e.from, 0 , SZ(G[e.from]) - 1 });
	}
	
	ll single_flow(ll from, ll to, ll flow) {
		// make a single flow
		if (from == to)
			return flow;
		usedNode[from] = 1;
		rep(i, 0, G[from].size()) {
			RevEdge& e = G[from][i];
			if (usedNode[e.to] || e.cap <= 0)
				continue;
			ll flow_from_e = single_flow(e.to, to, min(flow, e.cap));
			if (flow_from_e > 0) {
				e.cap -= flow_from_e; assert(e.cap >= 0);
				G[e.to][e.rev].cap += flow_from_e;
				// get a larger flow
				return flow_from_e;
			}
		}
		// if we already visited all edges or cap = 0 flow = 0;
		return 0;
	}
	ll max_flow(ll from, ll to) {
		ll flow = 0;
		while (true) {
			fill_v(usedNode, 0);
			ll f = single_flow(from, to, INF);
			if (f == 0)
				return flow;
			else
				flow += f;
		}
	}
};

// Least Common Ancestor
class LCA {
public:
	LCA(const Graph& graph, ll root) : max_par(ceil(log2(graph.size()) + 2)), parent(graph.size(), vll(max_par,-1)),
		depth() {
		//parent[root][0] = root;
		graph.dfs(root, [&](const Edge & e) {
			ll to = e.to;
			parent[to][0] = e.from;
			rep(i, 1, parent[to].size()) {
				if (parent[to][i - 1] == -1)
					return;
				else
					parent[to][i] = (parent[parent[to][i - 1]][i - 1]);
			}
		});
		depth = graph.dijkstra(root);
	}
	ll operator()(ll node1, ll node2) {
		if (depth[node1] > depth[node2]) swap(node1, node2);
		rrep(i, 0, max_par) {
			if (((depth[node2] - depth[node1]) >> i) & 1) {
				node2 = parent[node2][i];
			}
		}
		if (node1 == node2)return node1;
		rrep(i, 0, max_par) {
			if (parent[node1][i] != parent[node2][i]) {
				node1 = parent[node1][i];
				node2 = parent[node2][i];
			}
		}
		return parent[node1][0];
	}
private:
	ll max_par;
	vvll parent;
	vll depth;
};

class BipartiteMatching {
	// O(V*E)
	int n, left, right;
	vector< vector< int > > graph;
	vector< int > used;
	int timestamp;
public:
	BipartiteMatching(int left, ll right) : n(left+right), left(left), right(right), graph(n), used(n, 0), timestamp(0){}

	void push(int u, int v) {
		graph[u].push_back(v + left);
		graph[v + left].push_back(u);
	}

	bool dfs(int idx, vector<int>& match) {
		used[idx] = timestamp;
		for (auto& to : graph[idx]) {
			int to_match = match[to];
			if (to_match == -1 || (used[to_match] != timestamp && dfs(to_match, match))) {
				match[idx] = to;
				match[to] = idx;
				return true;
			}
		}
		return false;
	}

	int bipartite_match(vector<int>& match) {
		match.resize(n); fill_v(match, -1);
		int ret = 0;
		for (int i = 0; i < SZ(graph); i++) {
			if (match[i] == -1) {
				++timestamp;
				ret += dfs(i, match);
			}
		}
		return ret;
	}

	int bipartite_match() {
		vector<int> match;
		return bipartite_match(match);
	}
};



// ================= Rectangle Area Problem =====================
auto getNeighbor = [](ll i, ll w, ll h) {
	ll H = i / w;
	ll W = i % w;
	vll res;
	if (H > 0) res.push_back(i - w);
	if (H < h - 1) res.push_back(i + w);
	if (W > 0)res.push_back(i - 1);
	if (W < w - 1)res.push_back(i + 1);
	return res;
};

auto getHW = [](ll i, ll w) {
	ll H = i / w;
	ll W = i % w;
	return pll{ H,W };
};









// ============================ Header  =================================

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(12);

	Point Ps, Pt;
	read(Ps); read(Pt);
	ll n; cin >> n;
	Graph_Base<double> g(n+2);
	vpt p(n+2); vll r(n+2);
	rep(i, 0, n) {
		cin >> p[i].x >> p[i].y >> r[i];
	}
	p[n]=(Ps); p[n+1] = (Pt);
	r[n] = 0; r[n + 1] = 0;

	rep(i, 0, n+2) {
		rep(j, 0, n+2) {
			double dx = p[i].x - p[j].x;
			double dy = p[i].y - p[j].y;
 			double dist = sqrt(dx*dx + dy*dy);
			double d = max(0., dist - r[i] - r[j]);
			auto e = Edge_Base<double>{ i,j, d };
			g.push(e);
		}
	}
	auto res = g.dijkstra(n);
	cout << res[n + 1] << endl;

	return 0;
}
