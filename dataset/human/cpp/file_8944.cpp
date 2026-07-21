#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<string> A;
vector<string> B;
int N, M;
bool flag = false;
string answer = "No";

void search(vector<string> C, int y, int x) {
    int temp_x;
    int temp_y;
    temp_y = y;
    for (int i = 0; i < M; ++i) {
        temp_x = x;
        for (int j = 0; j < M; ++j) {
            if (temp_x < N && temp_y < N) {
                if (C[temp_y][temp_x] == B[i][j]) {
                    flag = true;
                    if (j == M - 1 && i == M - 1 & flag == true) {
                        answer = "Yes";
                    }
                } else {
                    flag = false;
                    break;
                }
            ++temp_x;
            }
        }
        ++temp_y;
        if (flag == false) break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    A.resize(N);
    B.resize(M);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }

    for (int y = 0; y < N; ++y) {
      for (int x = 0; x < N; ++x) {
          search(A, y, x);
      }
    }
    cout << answer << endl;

    return 0;
}
