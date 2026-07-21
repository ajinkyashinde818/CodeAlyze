#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <fstream>
#include <iterator>
#include <random>
#include <chrono>
 
 
#define forr(i,start,count) for (int i = (start); i < (start)+(count); ++i)
#define set_map_includes(set, elt) (set.find((elt)) != set.end())
#define readint(i) int i; cin >> i
#define readll(i) ll i; cin >> i
#define readdouble(i) double i; cin >> i
#define readstring(s) string s; cin >> s
 
typedef long long ll;
 
using namespace std;
 
 
template<class T>
class depth_first_search_iterator {
  public:
    stack<pair<T,T>> todo;
    function<bool(T)> notvisited;
    function<void(T)> mark_visited;
    function<set<T>(T)> neighbors;
 
    depth_first_search_iterator() {}
 
    depth_first_search_iterator(T start, function<bool(T)> notv, function<void(T)> mark_v, function<set<T>(T)> neigh) :
      notvisited(notv), mark_visited(mark_v), neighbors(neigh), end_(false), current(start), prev(start) {
          todo.push(make_pair(start, start)); operator++();
    }
 
    void operator++() {
        end_ = true;
        while (!todo.empty()) {
            current = todo.top().first; prev = todo.top().second; todo.pop();
            if (notvisited(current)) {
                mark_visited(current);
                for (const T x : neighbors(current)) {  todo.push(make_pair(x, current));   }
                end_ = false;
                break;
            }
        }
    }
 
    T operator*() {     return current;    }
 
    T previous() {  return prev;  }
 
    bool end() {  return end_;  }
 
  private:
    T current; // contains current node
    T prev;    // contains previous node
    bool end_;
};
 
template<class T>
class breadth_first_search_iterator {
  public:
    queue<pair<T,T>> todo;
    function<bool(T)> notvisited;
    function<void(T)> mark_visited;
    function<set<T>(T)> neighbors;
 
    breadth_first_search_iterator() {}
 
    breadth_first_search_iterator(T start, function<bool(T)> notv, function<void(T)> mark_v, function<set<T>(T)> neigh) :
      notvisited(notv), mark_visited(mark_v), neighbors(neigh), end_(false), current(start), prev(start) {
          todo.push(make_pair(start, start)); operator++();
    }
 
    void operator++() {
        end_ = true;
        while (!todo.empty()) {
            current = todo.front().first; prev = todo.front().second; todo.pop();
            if (notvisited(current)) {
                mark_visited(current);
                for (const T x : neighbors(current)) {  todo.push(make_pair(x, current));   }
                end_ = false;
                break;
            }
        }
    }
 
    T operator*() {     return current;    }
 
    T previous() {  return prev;  }
 
    bool end() {  return end_;  }
 
  private:
    T current;   // current node
    T prev;      // previous node
    bool end_;
};
 
template<class T>
class Graph {
    // allows only single connection between two vertices
    public:
      vector<T> vertices;
      vector<set<int>> neighbors;
      depth_first_search_iterator<int> dfs_iterator;
      breadth_first_search_iterator<int> bfs_iterator;
      vector<bool> visited;
 
      Graph() {}
 
      Graph(int n) {  for (int i = 0; i < n; ++i) {  AddVertex(0);  }   }
 
      void AddVertex(T val) {
          vertices.push_back(val);
          neighbors.push_back(set<int>());      }
 
      bool EdgeExists(int i, int j) {
          return (neighbors[i].find(j) != neighbors[i].end());
     }
 
      void AddEdge(int i, int j) {
          if (!EdgeExists(i,j)) {
            neighbors[i].insert(j);
            if (i != j) {         neighbors[j].insert(i);         } 
          }
      }
 
      T& operator[](int i) {      return vertices[i];      }
 
      void RemoveEdge(int i, int j) {
          if (EdgeExists(i,j)) {
            neighbors[i].erase(find(neighbors[i].begin(), neighbors[i].end(), j));
            neighbors[j].erase(find(neighbors[j].begin(), neighbors[j].end(), i));
          }
      }
 
      void dfs_init(int start) {
          visited = vector<bool>(vertices.size(), false);
          dfs_iterator = depth_first_search_iterator<int>(start, [this](int x){ return !visited[x]; }, [this](int x) { visited[x] = true;  },
            [this](int x) {  return neighbors[x];  } );
      }
 
      void bfs_init(int start) {
          visited = vector<bool>(vertices.size(), false);
          bfs_iterator = breadth_first_search_iterator<int>(start, [this](int x){ return !visited[x]; }, [this](int x) { visited[x] = true;  },
            [this](int x) {  return neighbors[x];  } );
      }
 
      void print_() {
          forr(i, 0, vertices.size()) {
              for (auto x : neighbors[i]) {
                  if (i <= x) {  cout << i << "-" << x << endl;  }                  
              }
          }
      }
};
 

 
int main()   {
    cout.precision(17);
    ll modd = 1000 * 1000 * 1000 + 7;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> rand_gen(0, modd);   // rand_gen(rng) gets the rand no
    ll infinit = 10000000000000000;
 
 
//    readint(test_cases);
    int test_cases = 1;
    forr(t, 1, test_cases) {
        readint(n);

        int k = 1;
        while (n > (k*(k+1))/2) {
            k++;
        }
        if ((k*(k+1))/2 != n) {
            cout << "No" << endl; break;
        }
        cout << "Yes" << endl;
        cout << k+1 << endl;
        vector<vector<int>> ans(k+1, vector<int>());
        int first = 1;
        for(int i = k; i >= 1; --i) {
            forr(j,k-i+2, i) {
                ans[k-i].push_back(first);
                ans[j-1].push_back(first);
                first++;
            }
        }

        for(auto x : ans) {
            cout << x.size() << " ";
            for(auto p : x) {
                cout << p << " ";
            }
            cout << endl;
        }

    }
    return 0;
}
