#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<string> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    vector<string> B(M);
    for (int i = 0; i < M; i++) {
        cin >> B.at(i);
    }

    string ans;
    for (int i = 0; i <= N - M; i++) {
        for (int j = 0; j <= N - M; j++) {
            ans = "Yes";
            for (int k = 0; k < M; k++) {
                for (int l = 0; l < M; l++) {
                    if (B.at(k).at(l) != A.at(i + k).at(j + l)) {
                        ans = "No";
                    }
                }
            }
            if (ans == "Yes") {
                cout << ans << endl;
                return 0;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
