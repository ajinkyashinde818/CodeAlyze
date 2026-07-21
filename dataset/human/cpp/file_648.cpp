#include <iostream>
#include <string>
using namespace std;

int main() {
    int r, g, b, n;
    cin >> r;
    cin >> g;
    cin >> b;
    cin >> n;
    int s = 0;
    for (int i = 0; i <= n / r; i++) {
        for (int j = 0; j <= n / g; j++) {
            int x = i * r + j * g;
            if (x <= n && (n - x) % b == 0) {
                s++;
            }
        }
    }
    cout << s << endl;

	return 0;
}
