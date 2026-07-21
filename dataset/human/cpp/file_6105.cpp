#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct RMQ {
	using type = ll;
	static type id() { return LLONG_MIN; }
	static type op(const type& l, const type & r) { return max(l, r); }
};

template <typename M>
class segment_tree {
	using T = typename M::type;
	const int n;
	vector<T> data;
	int size(int n) {
		int res;
		for (res = 1; res < n; res <<= 1);
		return res;
	}
public:
	segment_tree(int n_) : n(size(n_)), data(n * 2, M::id()) {}
	segment_tree(int n_, T val) : n(size(n_)), data(n * 2, val) {}
	void init(const vector<T>& data_) {
		for (int i = 0; i < (int)data_.size(); i++)
			data[i + n] = data_[i];
		for (int i = n - 1; i >= 0; i--)
			data[i] = M::op(data[i * 2], data[i * 2 + 1]);
	}
	T find(int l, int r) {
		l += n; r += n + 1;
		T res1 = M::id(), res2 = M::id();
		while (l < r) {
			if (l & 1) res1 = M::op(res1, data[l++]);
			if (r & 1) res2 = M::op(data[--r], res2);
			l >>= 1; r >>= 1;
		}
		return M::op(res1, res2);
	}
};

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	ll N, C;
	cin >> N >> C;
	vector<ll> x(N), v(N), base(N);
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> v[i];
		sum += v[i];
		base[i] = sum - x[i];
	}
	segment_tree<RMQ> st(N);
	st.init(base);
	ll res = max(st.find(0, N - 1), 0LL), tmp = 0;
	for (int i = N - 1; i > 0; i--) {
		tmp += v[i];
		res = max(res, st.find(0, i - 1) + tmp - (C - x[i]) * 2);
	}
	sum = 0;
	for (int i = N - 1; i >= 0; i--) {
		sum += v[i];
		base[i] = sum - (C - x[i]);
	}
	st.init(base);
	res = max(res, st.find(0, N - 1));
	tmp = 0;
	for (int i = 0; i < N - 1; i++) {
		tmp += v[i];
		res = max(res, st.find(i + 1, N - 1) + tmp - x[i] * 2);
	}
	cout << res << endl;
	return 0;
}
