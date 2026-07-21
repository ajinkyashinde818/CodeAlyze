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
int N;
long long A[MAX_N];
long long dp[MAX_N][2];

int main(int argc, char **argv) {
    std::cin >> N;
    
    for (int i = 1; i <= N; i++) {
        std::cin >> A[i];
    }

    dp[1][0] = A[1] + A[2];
    dp[1][1] = -dp[1][0];

    for (int i = 2; i <= N - 1; i++) {
        dp[i][0] = std::max(dp[i-1][0] + A[i+1], dp[i-1][1] + A[i+1]);
        dp[i][1] = std::max(dp[i-1][0] - A[i] * 2 - A[i+1], + dp[i-1][1] + A[i] * 2 - A[i+1]);
    }

    std::cout << std::max(dp[N-1][0], dp[N-1][1]) << std::endl;

    return 0;
}
