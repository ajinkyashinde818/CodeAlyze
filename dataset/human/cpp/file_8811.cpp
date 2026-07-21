#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    int i, j, k, l, count;
    int M, N;
    char a, b;
    string tmp_str, ans;
    vector<string> A, B;
    // get input ----------------------
    cin >> N >> M;
    for(i = 0; i < N; i++) {
        cin >> tmp_str;
        A.push_back(tmp_str);
    }
    for(i = 0; i < M; i++) {
        cin >> tmp_str;
        B.push_back(tmp_str);
    }
    // search -------------------------
    ans = "No";
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            a = A[i][j];
            b = B[0][0];

            if(a == b) {
                count = 0;
                for(k = 0; k < M; k++) {
                    for(l = 0; l < M; l++) {
                        if(i+k >= N || j+l >= N) {
                            continue;
                        }

                        a = A[i+k][j+l];
                        b = B[k][l];

                        if(a == b) {
                            count++;
                        }
                    }
                }
                if(count == M*M) {
                    ans = "Yes";
                    break;
                }
            }
        }
    }
    // disp answer --------------------
    cout << ans << endl;
    return 0;
}
