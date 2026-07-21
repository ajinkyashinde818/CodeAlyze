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
	int a, b, c, n; scanf("%d%d%d%d", &a, &b, &c, &n);
	
	i64 ans = 0;
	for(int i = 0; i * a <= n; i++) {
		for(int j = 0; i * a + j * b <= n; j++) {
			int k = n - (i * a + j * b);
			if(k < 0 or k % c) continue;
			ans++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
