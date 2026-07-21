#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int ans = 0;
    for (int r=0;r*R<=N;r++){
        for (int g=0;g*G<=N;g++){
          	int p = N - r*R - g*G;
            if (p >= 0 && p % B == 0){
              	ans++;
            }
        }
    }
    cout << ans << endl;
}
