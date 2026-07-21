/*
このコード、と～おれ!
Be accepted!
∧＿∧　
（｡･ω･｡)つ━☆・*。
⊂　　 ノ 　　　・゜+.
　しーＪ　　　°。+ *´¨)
 　　　　　　　　　.· ´¸.·*´¨) ¸.·*¨)
			　　　　　　　　　　(¸.·´ (¸.·'* ☆
					*/

#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <climits>
#include <tuple>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <memory>
#include <iomanip>
#define rep(i, n) for(Int (i) = 0; (i) < (n); ++(i))
#define debug(var) cout << #var << ": " << var << endl
using namespace std;
using Int = int64_t;
using Uint = uint64_t;
constexpr Uint mod = 1e9 + 7;
constexpr Int INF = INT_MAX;
template<typename T>
using Grid = vector<vector<T>>; // 二次元配列。[y][x]
template<typename T, typename U>
using Umap = unordered_map<T, U>;
template<typename T>
using Uset = unordered_set<T>;
template<typename T>
using P = pair<T, T>;

int main() {

	Int N, R; cin >> N >> R;
	Int ans = 0;
	if (N >= 10)ans = R;
	else {
		ans = R +	 100 * (10 - N);
	}

	cout << ans << endl;

	return 0;
}
