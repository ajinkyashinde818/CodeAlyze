#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main(){
    long long R, G, B, N;
    cin >> R >> G >> B >> N;
    long long ans = 0;
    for(int r=0; r<=N; r++){
        for(int g=0; g<=N; g++){
            int tmp = N-(r*R+g*G);
            if(tmp < 0) continue;
            if(tmp % B == 0) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
