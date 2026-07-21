#include <iostream>
#include <vector>
#include <string>
// #include <map>
// #include <algorithm>
// #include <set>
// #include <cmath>

using namespace std;
// typedef unsigned long long ull;


int main(int argc, char const *argv[]) {
    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }

    bool hit = false;
    for (int i = 0; i <= N-M; ++i) {
        for (int j = 0; j <= N-M; ++j) {
            bool match = true;
            for (int k = 0; k < M; ++k) {
                for (int l = 0; l < M; ++l) {
                    if (A[i+k][j+l] != B[k][l]) {
                        match = false;
                        break;
                    }
                }
                if (!match) break;
            }
            if (match) {
                hit = true;
                break;
            }
        }
        if (hit) {
            break;
        }
    }

    if (hit) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
