#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main() {
    // 標準入力
    int R,G,B,N;
    cin >> R >> G>> B >> N;
    int ans=0;
    for (int r=0; r*R<=N; r++) {
        for (int g=0; (r*R)+(g*G)<=N; g++) {
            if ((N-((r*R)+(g*G)))%B==0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
