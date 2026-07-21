#include <iostream>

using namespace std;

int main(void) {
    int R, G, B, N, X=0;
    cin >> R >> G >> B >> N;
    for (int i=0;R*i<=N;i++) for (int j=0;G*j<=N-R*i;j++) {
        if ((N - R*i - G*j)%B == 0) X++;
    }
    cout << X << endl;

    return 0;
}
