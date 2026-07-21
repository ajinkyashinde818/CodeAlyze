#include <iostream>

int getPrivateRating(int K, int R) {
    if(K >= 10) {
        return R;
    } else {
        return R + (100 * (10 - K));
    }
}

int main(int argc, const char * argv[]) {
    int N(0), R(0);

    std::cin >> N >> R;

    int PrivateRating = getPrivateRating(N, R);

    std::cout << PrivateRating;

    return 0;
}
