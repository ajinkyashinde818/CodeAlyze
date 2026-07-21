#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N;
long long C;

int main() {
    cin >> N >> C;
    vector<int> v(N);
    vector<long long> x(N), cal(N);
    vector<long long> clock(N), clock_turn(N);
    cin >> x[0] >> v[0];
    cal[0] = v[0];
    clock[0] = max(v[0] - x[0], 0ll);
    clock_turn[0] = max(0ll, v[0] - 2 * x[0]);
    for (int i = 1; i < N; i++) {
        cin >> x[i] >> v[i];
        cal[i] = cal[i - 1] + v[i];
        clock[i] = max(clock[i - 1], cal[i] - x[i]);
        clock_turn[i] = max(clock_turn[i - 1], cal[i] - x[i] * 2);
    }
  
    //反時計回りでも計算
    vector<long long> anti(N), anti_turn(N);
    cal[0] = v[N - 1];
    anti[N - 1] = max(v[N - 1] - C + x[N - 1], 0ll);
    anti_turn[N - 1] = max(0ll, v[N - 1] - 2 * (C - x[N - 1]));
    for (int i = 1; i < N; i++) {
        cal[i] = cal[i - 1] + v[N - i - 1];
        anti[N - i - 1] = max(anti[N - i], cal[i] - C + x[N - i - 1]);
        anti_turn[N - i - 1] = max(anti_turn[N - i], cal[i] - (C - x[N - i - 1]) * 2);
    }
    
      long long ans = max(clock[N - 1], anti[0]);
    for (int i = 0; i < N - 1; i++) {
        long long tmp = max(clock_turn[i] + anti[i + 1], clock[i] + anti_turn[i + 1]);
 	    ans = max(tmp, ans);
    }
    
    cout << ans << endl;
}
