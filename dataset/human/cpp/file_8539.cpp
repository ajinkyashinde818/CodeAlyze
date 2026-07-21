#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int main() {
    int N, M;
    int count = 0;
    string s;
    string ans = "No";
    cin >> N >> M;
    vector<string>A;
    vector<string>B;

    for (int i = 0; i < N; i++) {
        cin >> s;
        A.push_back(s);
    }

    for (int i = 0; i < M; i++) {
        cin >> s;
        B.push_back(s);
    }

    for (int i = 0; i < N-M+1; i++) {
        for (int j = 0; j < N-M+1; j++) {
            count = 0;
            for (int k = 0; k < M; k++) {
                for (int l = 0; l < M; l++) {
                    if (A[j+l][i+k] == B[l][k]) {
                        count++;
                    } else {
                        goto L1;
                    }
                }
            }
            L1:
            if (count==M*M) {
                ans = "Yes";
                goto L2;
            }
        }
    }
L2:
    cout <<  ans << endl;
}
