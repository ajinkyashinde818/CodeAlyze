#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, M;
    const int nmax = 50;
    cin >> N >> M;

    char A[nmax][nmax], B[nmax][nmax];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> B[i][j];
        }
    }

    bool exist = false;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((i + M - 1 >= N) || (j + M - 1 >= N)) continue;

            bool match = true;
            for (int y = 0; y < M; y++) {
                for (int x = 0; x < M; x++) {
                    if (A[i + y][j + x] != B[y][x]) match = false;
                }
            }
            if (match) exist = true;
        }
    }

    if (exist) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
