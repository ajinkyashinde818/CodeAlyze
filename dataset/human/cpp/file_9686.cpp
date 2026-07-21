#include <iostream>
using namespace std;
const int NM_MAX = 50;
int main (void) {
    int N;
    int M;
    string A[NM_MAX];
    string B[NM_MAX];

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    int H = N - M;
    int BW = B[0].length();
    int W = A[0].length() - BW;
    for (int i = 0; i <= H; i++) {
        for (int j = 0; j <= W; j++) {
            bool match = true;
            for (int k = 0; k < M; k++) {
                if (A[i + k].substr(j, BW) != B[k]) {
                    match = false;
                }
            }
            if (match) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
