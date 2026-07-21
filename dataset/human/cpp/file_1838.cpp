//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <climits>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <random>
#include <complex>
#include <regex>

using namespace std;

#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOW_MAP(v){std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}

int main() {

    int N, M;
    cin >> N >> M;

    vector<int> a(N + 1, 0);
    vector<int> e(M);
    for (int i = 0; i < M; i++) cin >> e[i];

    vector<int> ans;
    for (int i = M - 1; i >= 0; i--) if (a[e[i]] == 0)ans.push_back(e[i]), a[e[i]] = 1;

    for (int i = 1; i <= N; i++) if (a[i] == 0) ans.push_back(i);

    for (auto x : ans) cout << x << endl;

    return 0;
}
