#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int R,G,B,N; cin>>R>>G>>B>>N;
    long ans = 0;
    for (int r = 0; r*R<=N; r++) {
        for (int g = 0; r*R+g*G <= N; g++) {
            if ((N - (r*R+g*G)) % B == 0)
                ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}
