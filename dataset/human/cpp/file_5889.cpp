#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

template<typename T>
std::vector<T> make_v(size_t a){return std::vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

int main() {
	int n; i64 c; scanf("%d%lld", &n, &c);
	std::vector<i64> x(n), v(n);
	for(int i = 0; i < n; i++) {
		scanf("%lld%lld", &x[i], &v[i]);
	}

	std::vector<i64> a(n + 1), A(n + 1);
	for(int i = 0; i < n; i++) a[i + 1] = a[i] + v[i];
	for(int i = 0; i < n; i++) a[i + 1] -= x[i];
	for(int i = 1; i < a.size(); i++) A[i] = std::max(A[i - 1], a[i]);

	reverse(begin(x), end(x)); reverse(begin(v), end(v));
	std::vector<i64> b(n + 1), B(n + 1);
	for(int i = 0; i < n; i++) b[i + 1] = b[i] + v[i];
	for(int i = 0; i < n; i++) b[i + 1] -= (c - x[i]);
	for(int i = 1; i < b.size(); i++) B[i] = std::max(B[i - 1], b[i]);
	reverse(begin(x), end(x)); reverse(begin(v), end(v));

	i64 ans = std::max(A.back(), B.back());
	for(i64 i = 0, tmp = 0; i < n; i++) {
		tmp += v[i];

		ans = std::max(ans, (tmp - x[i] * 2) + B[n - i - 1]);
	}
	
	for(i64 i = n - 1, tmp = 0; i >= 0; i--) {
		tmp += v[i];
		
		ans = std::max(ans, (tmp - (c - x[i]) * 2) + A[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
