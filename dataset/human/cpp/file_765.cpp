#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <numeric>

using namespace std;

int R, G, B, N;

int main() {
    cin >> R >> G >> B >> N;
    
    int ans = 0;
    for(int r=0;r*R<=N;r++){
        for(int g=0;g*G<=N;g++){
            if( (N - r*R - g*G) % B == 0 && r*R + g*G <= N ) ans++;
        }
    }

    cout << ans << endl;
}
