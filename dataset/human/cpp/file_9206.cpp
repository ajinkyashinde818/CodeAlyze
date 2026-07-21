#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

#define INF (1e9)

int N, M;

int main() {
    cin >> N >> M;

    vs A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vs B(N);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    for (int i = 0; i <= N - M; i++) {
        for (int j = 0; j <= N - M; j++) {
            bool f = true;
            for (int x = 0; x < M; x++) {
                for (int y = 0; y < M; y++) {
                    if (A[x + i][y + j] != B[x][y])
                        f = false;
                }
            }
            if (f) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
