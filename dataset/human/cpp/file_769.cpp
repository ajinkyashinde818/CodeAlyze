#include <iostream>
#include <vector>

int main() {
    int a, b, c, n; std::cin >> a >> b >> c >> n;
    unsigned long long cnt = 0;

    int aa = 0;
    while (aa * a <= n) {
        int bb = 0;
        while (aa * a + bb * b <= n) {
            if ((n - aa * a - bb * b) % c == 0) {
                cnt++;
            }
            bb++;
        }
        aa++;
    }

    std::cout << cnt << std::endl;
    return 0;
}
