#include<iostream>
#include<sstream>
#include<vector>
#include<iterator>
using namespace std;

int main(void)
{
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    long long ans = 0;
    for (int r = 0; r <= N; r += R) {
        for (int g = 0; g <= N - r; g += G) {
            int b = N - r - g;
            if (b%B == 0)
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
