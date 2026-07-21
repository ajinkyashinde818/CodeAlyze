#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Tree {
public:
	explicit Tree(long long L) {
		nodes.emplace_back(L);
	}
	void add(const string& s){
		int cur = 0;
		for(int i=0;i<s.size();i++){
			int& nextNode = nodes[cur].next[s[i]-'0'];
			if(nextNode == -1){
				nodes.emplace_back(nodes[cur].depth - 1);
				nextNode = nodes.size() - 1;
			}
			cur = nextNode;
		}
	}
	bool solve() const {
		long long grundy = 0LL;
		for(const auto& node : nodes){
			if(!node.valid()) continue;
			long long d = node.depth;
			grundy ^= d^(d&(d-1));
		}
		return grundy != 0LL;
	}
private:
	class Node {
	public:
		explicit Node(long long d) : depth(d), next(2, -1) {}
		bool valid() const{
			if(depth <= 0) return false;
			int cnt = 0;
			for(int t : next) if(t == -1) ++cnt;
			return cnt == 1;
		}
		long long depth;
		vector<int> next;
	};
private:
	vector<Node> nodes;
};

int main(){
	int N; long long L;
	while(cin >> N >> L){
		Tree tree(L);
		for(int i=0;i<N;i++){
			string s; cin >> s;
			tree.add(s);
		}
		cout << (tree.solve() ? "Alice" : "Bob") << endl;
	}
}
