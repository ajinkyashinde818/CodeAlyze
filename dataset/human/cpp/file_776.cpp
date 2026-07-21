#include <iostream>
using namespace std;
int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    long long int n = 0;
    for(int r = 0; r*R <= N; ++r) {
        for(int g = 0; r*R+g*G <= N; ++g) {
          if((r*R+g*G == N) || ((N-r*R-g*G) % B == 0)) {
              n += 1;
            }
        }
    }
    cout << n << endl;
}
