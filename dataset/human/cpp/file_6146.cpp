#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;


int n;
ull c;
// 返り値は
// {"ひたすら進んだ場合のmaxcalの寿司の位置", "ひたすら進んだ場合の最大摂取カロリー", "引き返す場合のmaxcalの寿司の位置", "引き返す場合の最大摂取カロリー"}
std::vector<std::vector<double>> solve(std::vector<std::vector<ull>> x){
	double nowcal = 0;
	double maxcal = 0;
	std::vector<std::vector<double>> ret(x.size(),std::vector<double> (2,0));
	for (size_t i = 1; i < x.size(); i++) {
		nowcal = nowcal + x[i][1] - (x[i][0] - x[i-1][0]);
		ret[i][0] = nowcal;
		maxcal = max(maxcal, nowcal - x[i][0]);
		ret[i][1] = maxcal;
	}
	return ret;
}


int main(int argc, char const *argv[]) {
	std::cin >> n >> c;
	// {"時計回りの距離", "反時計回りの距離", "カロリー"}
	std::vector<std::vector<ull>> x(n+1 ,std::vector<ull> (2,0));
	std::vector<std::vector<ull>> y(n+1 ,std::vector<ull> (2,0));
	x[0][0] = x[0][1] = 0;
	y[0][0] = y[0][1] = 0;
	for (size_t i = 0; i < n; i++) {
		std::cin >> x[i+1][0] >> x[i+1][1];
		y[i+1][0] = c - x[i+1][0];
		y[i+1][1] = x[i+1][1];
	}

	// x,yを小さい順にソート
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	// (反)時計回りに回った時にどこまで食うのが最もコスパが良いのか
	// (反)時計回りに回った時にどこまで食って戻るのが最もコスパが良いのかを探す
	std::vector<std::vector<double>> xx = solve(x);
	std::vector<std::vector<double>> yy = solve(y);

	double ans = 0;
	for (size_t i = 0; i < xx.size(); i++) {
		ans = max(ans, max(xx[i][0] + yy[n-i][1], yy[i][0] + xx[n-i][1]));
	}

	std::cout << (ull)ans << '\n';
	return 0;
}
