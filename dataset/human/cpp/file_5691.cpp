#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
using namespace std;

#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }
template<class T> ostream& operator << (ostream &s, set<T> P)
{ EACH(it, P) { s << "<" << *it << "> "; } return s << endl; }



const int NUM_OF_CHAR = 2;
const char START = '0';
struct Trie {
  vector<vector<int> >  tree;
  vector<int> length;
    
	void init() { tree.clear(); length.clear(); }
  void init(vector<string> list) {
	sort(list.begin(), list.end());
	tree.clear(); tree.push_back( vector<int>(NUM_OF_CHAR, 0) ); 
	length.clear(); length.push_back(0);
	for (int i = 0; i < list.size(); ++i) {
	  int it = 0;
	  string str = "";
	  for (int j = 0; j < list[i].size(); ++j) {
		str += list[i][j];
		if (tree[it][list[i][j] - START] == 0) {
		  tree.push_back( vector<int>(NUM_OF_CHAR, 0) ); 
		  tree[it][list[i][j] - START] = tree.size() - 1;
			length.push_back(str.size());
		}
		it = tree[it][list[i][j] - START];
	  }
	}       
  }
  
  inline vector<int>& operator [] (int i) {return tree[i];}
    
  int find(string str) {
	int it = 0;
	for (int i = 0; i < str.size(); ++i) {
	  if ( (it = tree[it][str[i]]) == 0 ) return -1;
	}
	return it;
  }
    
  friend ostream& operator << (ostream& s, const Trie& trie) {
		for (int i = 0; i < trie.tree.size(); ++i) { s << i << " : " << trie.length[i] << ", " << trie.tree[i] << endl; } return s;
  }
};

Trie trie;


int N;
long long L;
string S[110000];

int G[110000];

int main() {
	while (cin >> N >> L) {
        vector<string> vec;
        for (int i = 0; i < N; ++i) {
            cin >> S[i];
			vec.push_back(S[i]);
        }
		trie.init(vec);

		//COUT(trie);
        
        long long grundy = 0;
        for (int i = 0; i < trie.tree.size(); ++i) {
		  if (trie.length[i] == L) continue;
		  vector<int> node = trie.tree[i];
		  int num = 0;
		  for (int j = 0; j < node.size(); ++j) {
			if (node[j] != 0) continue;
			//string str = trie.length[i] + (char)('0' + j);
			//cout << i << ", " << j << ": " << str << endl;
		  
			long long depth = L - trie.length[i];
			long long tmp = 1;
			while (depth % 2 == 0) depth /= 2, tmp *= 2;
			grundy ^= tmp;
		  }
        }
        
        if (grundy == 0) puts("Bob");
        else puts("Alice");
	}
}
