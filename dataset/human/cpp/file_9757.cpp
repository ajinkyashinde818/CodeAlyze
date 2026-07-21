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
//#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

//#include <cv.h>
//#include <highgui.h>
#include <stdlib.h>
#include <string>

const int MAX_N = 100050;
const long long MOD = 1000000007;

int N;
std::string S;

long long cnt[30] = {};

int main(int argc, char **argv) {
    std::cin >> N;
    std::cin >> S;

    for (int i = 0; i < S.size(); i++) {
        cnt[S[i] - 'a']++;
    }

    long long ret = 1;
    for (int i = 0; i < 30; i++) {
        ret = (ret * (cnt[i] + 1)) % MOD;
    }

    std::cout << (ret - 1 + MOD) % MOD << std::endl;

    return 0;
}
