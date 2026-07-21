#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    for (int i=0;i<N;i++){
        cin >> A[i];
    }
    for (int i=0;i<M;i++){
        cin >> B[i];
    }
    bool ans = false;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            bool flag = true;
            for (int h=0;h<M;h++){
                for (int w=0;w<M;w++){
                    if (i+h>=N || j+w>=N) {
                        flag = false;
                        break;
                    }
                    if (A[i+h][j+w] != B[h][w]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (flag) {
                ans = true;
                break;
            }
        }
        if (ans) break;
    }

    if (ans) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}
