#include <bits/stdc++.h>

using namespace std;

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15);
  }
} initializer;

template<typename T> istream& operator>>(istream &s, vector<T> &v) {
  for (T &t : v) s >> t;
  return s;
}

template<typename T> ostream& operator<<(ostream &s, const vector<T> &v) {
  for (const T &t : v) s << t << endl;
  return s;
}

template<typename T> T min(vector<T>& v) {return *min_element(v.begin(), v.end());}

template<typename T> T max(vector<T>& v) {return *max_element(v.begin(), v.end());}

template<typename T> int min_element(vector<T>& v) {return min_element(v.begin(), v.end()) - v.begin();}

template<typename T> int max_element(vector<T>& v) {return max_element(v.begin(), v.end()) - v.begin();}

template<typename T> void sort(vector<T>& v) {sort(v.begin(), v.end());}

template<typename T, typename Function> void sort(vector<T>& v, Function func) {sort(v.begin(), v.end(), func);}

template<typename T> void rsort(vector<T>& v) {sort(v.rbegin(), v.rend());}

template<typename T> void reverse(vector<T>& v) {reverse(v.begin(), v.end());}

template<typename T> void unique(vector<T>& v) {v.erase(unique(v.begin(), v.end()), v.end());}

template<typename T> void nth_element(vector<T>& v, int n) {nth_element(v.begin(), v.begin() + n, v.end());}

template<typename T> bool next_permutation(vector<T>& v) {return next_permutation(v.begin(), v.end());}

template<typename T> int find(vector<T>& v, T t) {return find(v.begin(), v.end(), t) - v.begin();}

template<typename T> int in(vector<T> v, T t) {return find(v, t) != int(v.size());}

template<typename T> int lower_bound(vector<T>& v, T t) {return lower_bound(v.begin(), v.end(), t) - v.begin();}

template<typename T> int upper_bound(vector<T>& v, T t) {return upper_bound(v.begin(), v.end(), t) - v.begin();}

template<typename T> T accumulate(const vector<T>& v, function<T(T, T)> func = plus<T>()) {return accumulate(v.begin(), v.end(), T(), func);}

template<typename T> void adjacent_difference(vector<T>& v) {adjacent_difference(v.begin(), v.end(), v.begin());}

template<typename T> void adjacent_difference(vector<T>& v, vector<T>& u) {adjacent_difference(v.begin(), v.end(), u.begin());}

template<typename T> void partial_sum(vector<T>& v, vector<T>& u) {partial_sum(v.begin(), v.end(), u.begin());}

template<typename T> T inner_product(vector<T>& v, vector<T>& u) {return inner_product(v.begin(), v.end(), u.begin(), T(0));}

template<typename T> int count(const vector<T>& v, T t) {return count(v.begin(), v.end(), t);}

template<typename T, typename Function> int count_if(const vector<T>& v, Function func) {return count_if(v.begin(), v.end(), func);}

template<typename T, typename Function> void remove_if(vector<T>& v, Function func) {v.erase(remove_if(v.begin(), v.end(), func), v.end());}

template<typename T, typename Function> bool any_of(vector<T> v, Function func) {return any_of(v.begin(), v.end(), func);}

template<typename T> vector<T> subvector(vector<T>& v, int a, int b) {return vector<T>(v.begin() + a, v.begin() + b);}

template<typename T> int kinds(const vector<T>& v) {return set<T>(v.begin(), v.end()).size();}

template<typename T> void iota(vector<T>& v, T t = 0) {iota(v.begin(), v.end(), t);}

template<typename T> bool is_sorted(const vector<T>& v) {return is_sorted(v.begin(), v.end());}

template<typename T> class Addition {
public:
  template<typename V> T operator+(const V& v) const {
    return T(static_cast<const T&>(*this)) += v;
  }
};

template<typename T> class Subtraction {
public:
  template<typename V> T operator-(const V& v) const {
    return T(static_cast<const T&>(*this)) -= v;
  }
};

template<typename T> class Multiplication {
public:
  template<typename V> T operator*(const V& v) const {
    return T(static_cast<const T&>(*this)) *= v;
  }
};

template<typename T> class Division {
public:
  template<typename V> T operator/(const V& v) const {
    return T(static_cast<const T&>(*this)) /= v;
  }
};

template<typename T> class Modulus {
public:
  template<typename V> T operator%(const V& v) const {
    return T(static_cast<const T&>(*this)) %= v;
  }
};

template<typename T> class IndivisibleArithmetic : public Addition<T>, public Subtraction<T>, public Multiplication<T> {};

template<typename T> class Arithmetic : public IndivisibleArithmetic<T>, public Division<T> {};

template<typename T> class Ordered {
public:
  template<typename V> bool operator==(const V& v) const {
    return !(static_cast<T>(v) < static_cast<const T&>(*this) || static_cast<const T&>(*this) < static_cast<T>(v));
  }
  
  template<typename V> bool operator!=(const V& v) const {
    return static_cast<T>(v) < static_cast<const T&>(*this) || static_cast<const T&>(*this) < static_cast<T>(v);
  }

  template<typename V> bool operator>(const V& v) const {
    return static_cast<T>(v) < static_cast<const T&>(*this);
  }

  template<typename V> bool operator<=(const V& v) const {
    return !(static_cast<T>(v) < static_cast<const T&>(*this));
  }

  template<typename V> bool operator>=(const V& v) const {
    return !(static_cast<const T&>(*this) < static_cast<T>(v));
  }
};

template<typename T> int least_bit(T n) {
  static_assert(sizeof(T) == 4 || sizeof(T) == 8, "unsupported size");
  if (sizeof(T) == 4) return __builtin_ffs(n) - 1;
  if (sizeof(T) == 8) return __builtin_ffsll(n) - 1;
}

// n must be greater than 0.
template<typename T> int least_bit_fast(T n) {
  static_assert(sizeof(T) == 4 || sizeof(T) == 8, "unsupported size");
  if (sizeof(T) == 4) return __builtin_ctz(n);
  if (sizeof(T) == 8) return __builtin_ctzll(n);
}

template<typename T> int most_bit(T n) {
  static_assert(sizeof(T) == 4 || sizeof(T) == 8, "unsupported size");
  if (sizeof(T) == 4) return n ? 31 - __builtin_clz(n) : -1;
  if (sizeof(T) == 8) return n ? 63 - __builtin_clzll(n) : -1;
}

template<typename T> int count_bit(T n) {
  static_assert(sizeof(T) == 4 || sizeof(T) == 8, "unsupported size");
  if (sizeof(T) == 4) return __builtin_popcount(n);
  if (sizeof(T) == 8) return __builtin_popcountll(n);
}

template<typename T> T gcd(T t) {return t;}

template<typename T, typename... S> T gcd(T a, S... s) {
  auto b = gcd(s...);
  if (a == 0 || b == 0) return max(a, b);
  int fa = least_bit_fast(a);
  int fb = least_bit_fast(b);
  a >>= fa;
  b >>= fb;
  while (a != b) {
    auto& c = a > b ? a : b;
    c >>= least_bit_fast(c = abs(a - b));
  }
  return a << min(fa, fb);
}

template<typename T> T lcm(T t) {return t;}

template<typename T, typename... S> T lcm(T t, S... s) {
  T l = lcm(s...);
  return t / gcd(t, l) * l;
}

template<typename T> T floor(T a, T b) {
  auto d = div(a, b);
  return d.quot - (d.rem && (a < 0) != (b < 0) ? 1 : 0);
}

template<typename T> T ceil(T a, T b) {
  auto d = div(a, b);
  return d.quot + (d.rem && (a > 0) == (b > 0) ? 1 : 0);
}

template<typename T> T round(T a, T b) {return floor(a + b / 2, b);}

template<typename T> T mod(T a, T b) {
  T c = a % b;
  return c < 0 ? c + abs(b) : c;
}

template<typename T> T factorial(T n) {return n <= 1 ? 1 : factorial(n - 1) * n;}

template<typename T> T square(T n) {return n * n;}

template<typename T> T cube(T n) {return n * n * n;}

template<typename T> T norm(T x1, T y1, T x2, T y2) {return square(x1 - x2) + square(y1 - y2);}

template<typename T> bool isSquare(T n) {return square(T(sqrt(n))) == n;}

template<typename T> T clamp(T v, T l, T u) {return v < l ? l : v > u ? u : v;}

class Real : public Arithmetic<Real>, public Ordered<Real> {
private:
  long double val;

public:
  static long double EPS;

  Real() {}

  Real(long double val) : val(val) {}

  Real operator-() const {return -val;}

  template<typename T> Real operator+=(const T& r) {
    val += static_cast<long double>(r);
    return *this;
  }

  template<typename T> Real operator-=(const T& r) {
    val -= static_cast<long double>(r);
    return *this;
  }

  template<typename T> Real operator*=(const T& r) {
    val *= static_cast<long double>(r);
    return *this;
  }

  template<typename T> Real operator/=(const T& r) {
    val /= static_cast<long double>(r);
    return *this;
  }

  template<typename T> Real operator-(const T& v) const {return Real(*this) -= v;}

  template<typename T> Real operator*(const T& v) const {return Real(*this) *= v;}

  template<typename T> Real operator/(const T& v) const {return Real(*this) /= v;}

  template<typename T> bool operator<(const T r) const {return val < static_cast<long double>(r) - EPS;}

  Real abs() const {return std::abs(val);}

  Real sqrt() const {return std::sqrt(val);}

  operator long double() const {return val;}
};

long double Real::EPS = 1e-10;

ostream& operator<<(ostream& os, const Real& a) {
  os << a;
  return os;
}

istream& operator>>(istream& is, Real& a) {
  long double n;
  is >> n;
  a = n;
  return is;
}

Real floor(const Real& r) {
  return floor(r);
}

class Point : public Arithmetic<Point>, public Ordered<Point> {
public:
  Real x, y;

  Point() {}

  Point(const Real& x) : x(x), y(0) {}

  Point(const Real& x, const Real& y) : x(x), y(y) {}

  Point operator+=(const Point& p) {
    x += p.x;
    y += p.y;
    return *this;
  }

  Point operator-=(const Point& p) {
    x -= p.x;
    y -= p.y;
    return *this;
  }

  Point operator*=(const Point& p) {
    Real xx = x * p.x - y * p.y;
    y = x * p.y + y * p.x;
    x = xx;
    return *this;
  }

  Point operator*=(const Real& r) {
    x *= r;
    y *= r;
    return *this;
  }

  Point operator/=(const Point& p) {
    Real nrm = p.norm();
    Real xx = (x * p.x + y * p.y) / nrm;
    y = (y * p.x - x * p.y) / nrm;
    x = xx;
    return *this;
  }

  Point operator/=(const Real& r) {
    x /= r;
    y /= r;
    return *this;
  }

  bool operator<(const Point& p) const {
    return (x == p.x) ? y < p.y : x < p.x;
  }

  Real norm() const {
    return x * x + y * y;
  }

  Real abs() const {
    return norm().sqrt();
  }

  Point conj() const {
    return Point(x, -y);
  }
};

Point operator*(const Real& real, const Point& point) {return point * real;}

Point operator/(const Real& real, const Point& point) {return point / real;}

ostream& operator<<(ostream& os, const Point& point) {
  os << point.x << " " << point.y;
  return os;
}

istream& operator>>(istream& is, Point& point) {
  Real x, y;
  is >> x >> y;
  point = Point(x, y);
  return is;
}

class Circle {
public:
  Point c;
  Real r;

  Circle() {}

  Circle(Point c, Real r) : c(c), r(r) {}

  Circle(Real x, Real y, Real r) : c(x, y), r(r) {}
};

ostream& operator<<(ostream& os, const Circle& circle) {
  os << circle.c.x << " " << circle.c.y << " " << circle.r;
  return os;
}

istream& operator>>(istream& is, Circle& circle) {
  Real x, y, r;
  is >> x >> y >> r;
  circle = Circle(x, y, r);
  return is;
}

class Line {
public:
  Point a, b;

  Line() {}

  Line (const Point& a, const Point& b) : a(a), b(b) {}

  bool operator==(const Line& line) const {
    return ((line.vec() / vec()).y == 0) && (((line.a - a) / vec()).y == 0);
  }

  Point vec() const {
    return b - a;
  }
};

ostream& operator<<(ostream& os, const Line& line) {
  os << line.a << " " << line.b;
  return os;
}

istream& operator>>(istream& is, Line& line) {
  Point a, b;
  is >> a >> b;
  line = Line(a, b);
  return is;
}

class Segment : public Line, public Ordered<Segment> {
public:
  Segment() {}

  Segment (const Point& a, const Point& b) : Line(a, b) {}

  bool operator<(const Segment& segment) const {
    return a == segment.a ? b < segment.b : a < segment.a;
  }
};

enum CCW{LEFT = 1, RIGHT = 2, BACK = 4, FRONT = 8, ON = 16};

int ccw(const Point& a, const Point& b, const Point& c) {
  Point p = (c - a) / (b - a);
  if (p.y > 0) return LEFT;
  if (p.y < 0) return RIGHT;
  if (p.x < 0) return BACK;
  if (p.x > 1) return FRONT;
  return ON;
}

int ccw(const Segment& segment, const Point& point) {
  return ccw(segment.a, segment.b, point);
}

int ccw(const Line& line, const Point& point) {
  int res = ccw(line.a, line.b, point);
  if (res == BACK || res == FRONT) res = ON;
  return res;
}

template<bool strict = false> bool intersect(const Line& line1, const Line& line2) {
  if (strict) return (line1.vec() / line2.vec()).y != 0;
  return ((line1.vec() / line2.vec()).y != 0) || (line1 == line2);
}

template<bool strict = false> bool intersect(const Line& line, const Segment& segment) {
  Point p1 = (segment.a - line.a) / line.vec(), p2 = (segment.b - line.a) / line.vec();
  if (strict) return p1.y * p2.y < 0;
  return p1.y * p2.y <= 0;
}

template<bool strict = false> bool intersect(const Segment& segment, const Line& line) {
  return intersect(line, segment);
}

template<bool strict = false> bool intersect(const Segment& segment1, const Segment& segment2) {
  int ccw1 = ccw(segment1, segment2.a) | ccw(segment1, segment2.b);
  int ccw2 = ccw(segment2, segment1.a) | ccw(segment2, segment1.b);
  if (strict) return (ccw1 & ccw2) == (LEFT | RIGHT);
  return ((ccw1 & ccw2) == (LEFT | RIGHT)) || ((ccw1 | ccw2) & ON);
}

Real distance(const Segment& segment, const Point& point) {
  Point p = (point - segment.a) / segment.vec();
  if (p.x < 0) return (p * segment.vec()).abs();
  if (p.x > 1) return ((p - Point(1, 0)) * segment.vec()).abs();
  return (p.y * segment.vec()).abs();
}

Real distance(const Segment& segment1, const Segment& segment2) {
  if (intersect(segment1, segment2)) return 0;
  return min(min(distance(segment1, segment2.a), distance(segment1, segment2.b)), min(distance(segment2, segment1.a), distance(segment2, segment1.b)));
}

Real distance(const Circle& circle1, const Circle& circle2) {
  return max((circle1.c - circle2.c).abs() - circle1.r - circle2.r, Real(0));
}

template<typename Edge> class Graph {
public:
  using EdgeType = Edge;
  virtual int size() const = 0;
  template<typename... Args> void addEdge(int from, int to, Args...) {}
  template<typename... Args> void addUndirectedEdge(int from, int to, Args...) {}

  vector<pair<int, Edge>> getAllEdges() const {
    vector<pair<int, Edge>> res;
    for (int i = 0; i < size(); ++i) {
      for (const auto& edge : getEdges(i)) {
        res.emplace_back(i, edge);
      }
    }
    return res;
  }

  virtual vector<Edge> getEdges(int from) const = 0;
  virtual vector<Edge> getEdges(int from, int to) const = 0;
  virtual int getDegree(int v) const = 0;

  vector<int> getIndegree() const {
    vector<int> degree(size());
    for (const auto& edge : getAllEdges()) ++degree[edge.second.to];
    return degree;
  }
};

template<typename Edge> class AdjacencyList : public Graph<Edge> {
protected:
  vector<vector<Edge>> graph;

public:
  AdjacencyList(int n) : graph(n) {}

  int size() const {
    return graph.size();
  }
  
  template<typename... Args> void addEdge(int from, int to, Args... args) {
    graph[from].emplace_back(to, args...);
  }

  template<typename... Args> void addUndirectedEdge(int from, int to, Args... args) {
    addEdge(from, to, args...);
    addEdge(to, from, args...);
  }

  vector<Edge> getEdges(int from) const {
    return graph[from];
  }

  vector<Edge> getEdges(int from, int to) const {
    vector<Edge> res;
    for (const auto& edge : graph[from]) {
      if (edge.to == to) res.emplace_back(edge);
    }
    return res;
  }

  int getDegree(int v) const {
    return graph[v].size();
  }

  vector<Edge>& operator[](int v) {
    return graph[v];
  }
};

struct Edge {
  using CostType = int;
  const static int cost = 1;
  int to;
  Edge(int to) : to(to) {};
};

template<typename Cost> struct WeightedEdge : public Edge {
  using CostType = Cost;
  Cost cost;
  WeightedEdge(int to, Cost cost = 0) : Edge(to), cost(cost) {}
};

template<typename Capacity> struct ResidualEdge : public Edge {
  using CapacityType = Capacity;
  Capacity cap;
  int rev;
  ResidualEdge(int to, Capacity cap) : Edge(to), cap(cap) {}
  ResidualEdge reverse(int from) const {return ResidualEdge(from, 0);}
};

template<typename Capacity, typename Cost> struct WeightedResidualEdge : public ResidualEdge<Capacity> {
  Cost cost;
  WeightedResidualEdge(int to, Capacity cap, Cost cost) : ResidualEdge<Capacity>(to, cap), cost(cost) {}
  WeightedResidualEdge reverse(int from) const {return WeightedResidualEdge(from, 0, -cost);}
};

template<typename Graph, typename State> class Search {
protected:
  using Edge = typename Graph::EdgeType;

  const Graph graph;
  vector<bool> visited;

  virtual void push(const State&) = 0;
  virtual State next() = 0;
  virtual bool isRunning() = 0;

  virtual void visit(const State&) {}

public:
  Search(const Graph& graph) : graph(graph), visited(graph.size(), false) {}

  void solve(vector<int> from) {
    for (int i : from) push(State(i));
    while (isRunning()) {
      State now = next();
      int pos = now.getPos();
      if (visited[pos]) continue;
      visited[pos] = true;
      visit(now);
      for (const Edge& edge : graph.getEdges(pos)) {
        State nextState = now.next(pos, edge);
        if (visited[nextState.getPos()]) continue;
        push(nextState);
      }
    }
  }

  void solve(int from) {solve(vector<int>({from}));}

  bool isReachable(int v) {return visited[v];}
};

template<typename Edge> class Tree {
public:
  vector<Edge> parent;
  vector<vector<int>> children;
  vector<int> depth;

  Tree() {}

  Tree(int n) : children(n), depth(n, -1) {
    for (int i = 0; i < n; ++i) parent.emplace_back(i);
  }

  int size() const {
    return parent.size();
  }
  
  template<typename... Args> void addEdge(int from, int to, Args... args) {
    parent[from] = Edge(to, args...);
    children[to].emplace_back(from);
  }

  void addEdge(int from, const Edge& edge) {
    parent[from] = edge;
    children[edge.to].emplace_back(from);
  }

  int getDepth(int v) {
    if (depth[v] != -1) return depth[v];
    if (parent[v].to == v) return depth[v] = 0;
    return depth[v] = getDepth(parent[v].to) + 1;
  }

  vector<int> getPath(int v) {
    vector<int> res{v};
    while (v != parent[v].to) {
      v = parent[v].to;
      res.emplace_back(v);
    }
    return res;
  }
};

template<typename Edge> struct DijkstraState {
  using Cost = typename Edge::CostType;

  int from;
  Edge edge;
  Cost cost;

  DijkstraState(const int pos) : from(pos), edge(pos), cost(0) {}

  DijkstraState(const int from, const Edge& edge, const Cost cost) : from(from), edge(edge), cost(cost) {}

  DijkstraState next(const int from, const Edge& edge) const {return DijkstraState(from, edge, cost + edge.cost);}

  bool operator<(const DijkstraState& state) const {return cost > state.cost;}

  int getPos() const {return edge.to;}
};

template<typename Graph, bool Restoration = false, typename State = DijkstraState<typename Graph::EdgeType>> class Dijkstra : public Search<Graph, State> {
protected:
  using Edge = typename Graph::EdgeType;
  using Cost = typename Edge::CostType;

  constexpr static Cost INF = numeric_limits<Cost>::max();

  priority_queue<State> que;

  void push(const State& state) {
    if (dis[state.getPos()] <= state.cost) return;
    que.push(state);
    dis[state.getPos()] = state.cost;
  }

  State next() {
    State now = que.top();
    que.pop();
    return now;
  }

  bool isRunning() {return !que.empty();}

  void visit(const State& state) {
    if (Restoration) {
      int from = state.from, to = state.edge.to;
      if (from != to) {
        auto e = state.edge;
        e.to = from;
        shortestPathTree.addEdge(to, e);
      }
    }
  }

public:
  vector<Cost> dis;
  Tree<Edge> shortestPathTree;

  Dijkstra(const Graph& graph) : Search<Graph, State>(graph), dis(graph.size(), INF) {
    if (Restoration) shortestPathTree = Tree<Edge>(graph.size());
  }
};

template<typename Graph> Dijkstra<Graph> shortestPath(Graph& graph, int from) {
  Dijkstra<Graph> dijkstra(graph);
  dijkstra.solve(from);
  return dijkstra;
}

template<typename Graph> typename Graph::EdgeType::CostType shortestPath(Graph& graph, int from, int to) {
  return shortestPath(graph, from).dis[to];
}

template<typename Graph> Dijkstra<Graph, true> shortestPathTree(Graph& graph, int from) {
  Dijkstra<Graph, true> dijkstra(graph);
  dijkstra.solve(from);
  return dijkstra;
}

int main() {
  double xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  int n;
  cin >> n;
  vector<Circle> c(n);
  cin >> c;
  c.emplace_back(xs, ys, 0);
  c.emplace_back(xt, yt, 0);
  AdjacencyList<WeightedEdge<long double>> graph(n + 2);
  for (int i = 0; i < n + 2; ++i) {
    for (int j = i + 1; j < n + 2; ++j) {
      graph.addUndirectedEdge(i, j, distance(c[i], c[j]));
    }
  }
  cout << shortestPath(graph, n, n + 1) << endl;
}
