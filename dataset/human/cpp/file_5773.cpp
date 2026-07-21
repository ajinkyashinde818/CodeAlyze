#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

class Segment_Tree {
	vector<long long int>v;
	vector<long long int>add;
	vector<long long int>modi;
	vector<int>l;
	vector<int>r;
	int num;
	long long int ret;
	bool is_min;
	void Left(int place) {
		if (place >= v.size() / 2) {
			l[place] = place - v.size() / 2;
			return;
		}
		Left(place * 2);
		Left(place * 2 + 1);
		l[place] = l[place * 2];
		return;
	}
	void Right(int place) {
		if (place >= v.size() / 2) {
			r[place] = place - v.size() / 2;
			return;
		}
		Right(place * 2);
		Right(place * 2 + 1);
		r[place] = r[place * 2 + 1];
		return;
	}
	long long int Update(int place) {
		if (place >= v.size() / 2) {
			return v[place];
		}
		if (is_min) {
			v[place] = min(Update(place * 2), Update(place * 2 + 1));
			return v[place];
		}
		v[place] = max(Update(place * 2), Update(place * 2 + 1));
		return v[place];
	}
	void Modify(int a, int b, long long int num, int place) {
		if (l[place] >= a && r[place] <= b) {
			modi[place] = num;
			v[place] = num;
			add[place] = 0;
			return;
		}
		if (l[place] > b || r[place] < a)return;
		if (modi[place] != LLONG_MAX) {
			modi[place * 2] = modi[place * 2 + 1] = modi[place];
			v[place * 2] = v[place * 2 + 1] = modi[place];
			add[place * 2] = add[place * 2 + 1] = 0;
			modi[place] = LLONG_MAX;
		}
		add[place * 2] += add[place];
		add[place * 2 + 1] += add[place];
		add[place] = 0;
		Modify(a, b, num, place * 2);
		Modify(a, b, num, place * 2 + 1);
		if (is_min)v[place] = min(v[place * 2] + add[place * 2], v[place * 2 + 1] + add[place * 2 + 1]);
		else v[place] = max(v[place * 2] + add[place * 2], v[place * 2 + 1] + add[place * 2 + 1]);
		return;
	}
	void Add(int a, int b, long long int num, int place) {
		if (l[place] >= a && r[place] <= b) {
			if (modi[place] != LLONG_MAX) {
				if (place * 2 < v.size()) {
					modi[place * 2] = modi[place * 2 + 1] = modi[place];
					v[place * 2] = v[place * 2 + 1] = modi[place];
					add[place * 2] = add[place * 2 + 1] = 0;
				}
				modi[place] = LLONG_MAX;
			}
			add[place] += num;
			return;
		}
		if (l[place] > b || r[place] < a)return;
		if (modi[place] != LLONG_MAX) {
			modi[place * 2] = modi[place * 2 + 1] = modi[place];
			v[place * 2] = v[place * 2 + 1] = modi[place];
			add[place * 2] = add[place * 2 + 1] = 0;
			modi[place] = LLONG_MAX;
		}
		add[place * 2] += add[place];
		add[place * 2 + 1] += add[place];
		add[place] = 0;
		Add(a, b, num, place * 2);
		Add(a, b, num, place * 2 + 1);
		if (is_min)v[place] = min(v[place * 2] + add[place * 2], v[place * 2 + 1] + add[place * 2 + 1]);
		else v[place] = max(v[place * 2] + add[place * 2], v[place * 2 + 1] + add[place * 2 + 1]);
		return;
	}
	void RMQ(int a, int b, int place) {
		if (l[place] >= a && r[place] <= b) {
			if (modi[place] != LLONG_MAX) {
				if (place * 2 < v.size()) {
					modi[place * 2] = modi[place * 2 + 1] = modi[place];
					v[place * 2] = v[place * 2 + 1] = modi[place];
					add[place * 2] = add[place * 2 + 1] = 0;
				}
				modi[place] = LLONG_MAX;
			}
			if (is_min)ret = min(ret, v[place] + add[place]);
			else ret = max(ret, v[place] + add[place]);
			return;
		}
		if (l[place]>b || r[place]<a) return;
		if (modi[place] != LLONG_MAX) {
			modi[place * 2] = modi[place * 2 + 1] = modi[place];
			v[place * 2] = v[place * 2 + 1] = modi[place];
			add[place * 2] = add[place * 2 + 1] = 0;
			modi[place] = LLONG_MAX;
		}
		add[place * 2] += add[place];
		add[place * 2 + 1] += add[place];
		add[place] = 0;
		RMQ(a, b, place * 2);
		RMQ(a, b, place * 2 + 1);
		if (is_min)v[place] = min(v[place * 2] + add[place * 2], v[place * 2 + 1] + add[place * 2 + 1]);
		else v[place] = max(v[place * 2] + add[place * 2], v[place * 2 + 1] + add[place * 2 + 1]);
		return;
	}
public:
	Segment_Tree(int n, bool min) {
		n++;
		num = 1;
		while (num < n * 2) {
			num *= 2;
		}
		l.resize(num);
		r.resize(num);
		is_min = min;
		if (min) {
			v.resize(num, MOD*MOD);
		}
		else v.resize(num, -MOD * MOD);
		add.resize(num, 0);
		modi.resize(num, MOD*MOD);
		Left(1);
		Right(1);
	}
	void Insert(int place, long long int num, bool update) {
		place += v.size() / 2;
		v[place] = num;
		if (!update)return;
		place /= 2;
		while (place) {
			if (is_min)v[place] = min(v[place * 2], v[place * 2 + 1]);
			else v[place] = max(v[place * 2], v[place * 2 + 1]);
			place /= 2;
		}
	}
	void Modify(int a, int b, long long int num) {
		Modify(a, b, num, 1);
	}
	void Add(int a, int b, long long int num) {
		Add(a, b, num, 1);
	}
	void Init() {
		Update(1);
	}
	long long int RMQ(int a, int b) {
		if (is_min)ret = LLONG_MAX;
		else ret = LLONG_MIN;
		RMQ(a, b, 1);
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<string>s(N);
	for (auto &i : s)cin >> i;
	sort(s.begin(), s.end());
	Segment_Tree sg(100010, true);
	sg.Modify(0, 100010, 0);
	sg.Add(1, s[0].size(), 1);
	//K = 0;
	//for (int i = 0; i < N; i++) {
	//	if (s[i].size() > K)K = s[i].size();
	//	cout << s[i].size() << endl;
	//}
	for (int i = 1; i < N ; i++) {
		int index = 0;
		while (s[i - 1].size() > index&&s[i].size() > index&&s[i - 1][index] == s[i][index])index++;
		sg.Add(index + 1, index + 1, -1);
		if (index + 2 <= s[i].size())sg.Add(index + 2, s[i].size(), 1);
		//cout << index << endl;
	}
	long long int ans = 0;
	for (int i = 0; i <= 100006; i++) {
		//cout << i << " " << sg.RMQ(i,i) << endl;
		if (K+1-i<=0)break;
		if (sg.RMQ(i, i) & 1) {
			long long int box = K + 1 - i;
			long long int add = 1;
				cerr << box << " ";
			while (!(box & 1)) {
				box >>= 1;
				add <<= 1;
			}
				cerr << add << endl;
			ans ^= add;
		}
	}
	if (!ans)cout << "Bob\n";
	else cout << "Alice\n";
	return 0;
}
