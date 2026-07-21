#include <iostream>
#include <string>

typedef long long ll;

const int ms = 200200;

struct node {
	node() {
		to[0] = to[1] = -1;
		end = false;
	}

	int to[2];
	bool end;
};

int c = 1;
node trie[ms];

void go(std::string &str) {
	int on = 0;
	//std::cout << str << '\n';
	for(auto a : str) {
		if(trie[on].to[a - '0'] == -1) {
			//std::cout << "created " << c << "\n";
			trie[on].to[a - '0'] = c++;
		}
		on = trie[on].to[a - '0'];
	}
	//std::cout << "ended on " << on << "\n";
	trie[on].end = true;
}

ll nimber(int on, ll nim) {
	if(trie[on].end) {
		return 0;
	}
	ll ans = 0;
	for(int i = 0; i < 2; i++) {
		if(trie[on].to[i] == -1) {
			ll x = nim & -nim;
			//std::cout << "adding " << x << " on " << on << "\n";
			ans ^= x;
		} else {
			ans ^= nimber(trie[on].to[i], nim - 1);
		}
	}
	return ans;
}

int main() {
	int n;
	ll l;
	std::cin >> n >> l;
	while(n--) {
		std::string str;
		std::cin >> str;
		go(str);
	}
	if(nimber(0, l) == 0) {
		std::cout << "Bob\n";
	} else {
		std::cout << "Alice\n";
	}
}
