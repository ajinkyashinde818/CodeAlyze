#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>



int R, G, B, N;

int main(int argc, char **argv) {
    std::cin >> R >> G >> B >> N;

    long long ret = 0;
    for (int i = 0; i <= N / R; i++) {
        for (int j = 0; j <= N / G; j++) {
            int cur = i*R + j*G;
            if (cur <= N && (N - cur) % B == 0) {
                ret++;
            }
        }
    }

    std::cout << ret << std::endl;


    return 0;
}
