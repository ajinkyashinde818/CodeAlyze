#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <array>
#include <cmath>

using namespace std;

using ll = long long int;

// GCDを計算します
template <typename NumType>
NumType calcGCD(NumType a, NumType b) {
    if (a < b) {
        NumType tmp = a;
        a = b;
        b = tmp; 
    }

    NumType r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

// 約数を数えます
template <typename NumType>
NumType cntDivisor(const NumType & num) {
    NumType cnt = 0;
    for(NumType i = 1; i * i <= num; ++i) {
        if(num % i == 0) {
            cnt++;
            if(i * i != num) cnt++;
        }
    }

    return cnt;
}

// [beg, end)の範囲を，添え字indexでループするfor文に置換します
#define FOR_RANGE(index, beg, end)     for (ll index = beg; index < N; ++index)

#define DEBUG(x)     std::cout << #x << " : " << x << "\n"

int main() {
    int R, G, B, N;

    cin >> R >> G >> B >> N;

    int enumB[3001];
    for (int i = 0; i <= 3000; i++) {
        enumB[i] = i*B;
    }

    ll cnt = 0;
    for (int r = 0; R * r <= N; r++) {
        for (int g = 0; R * r + G * g <= N; g++) {
            if (binary_search(enumB, enumB + 3001, N - R*r - G*g)) cnt++;
        }
    }

    cout << cnt;

    return 0;
}
