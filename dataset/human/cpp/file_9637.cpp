#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    char A[N][N], B[M][M];
    for(int i = 0;i < N;i++)
        for(int t = 0;t < N;t++)
            cin >> A[i][t];
    for(int i = 0;i < M;i++)
        for(int t = 0;t < M;t++)
            cin >> B[i][t];

    for(int i = 0;i <= N - M;i++){
        for(int t = 0;t <= N - M;t++) {
            bool inc = true;
            for(int x = 0;x < M;x++) {
                for(int y = 0;y < M;y++) {
                    if(A[x+i][y+t] != B[x][y]) {
                        x = 100;
                        y = 100;
                        inc = false;
                    }
                }
            }
            if(inc) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
