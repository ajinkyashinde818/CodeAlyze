#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <list>
#include <math.h>
#include <algorithm>
#include <chrono>
#include <random>
#include <queue>
#include <fstream>
#include <iterator> // std::back_inserter
#include <chrono>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <float.h>
#include <cassert>
#include <functional>

using namespace std;

int main(int argc, char *argv[])
{
    int N, K;
    int ans;

    cin >> N >> K;

    if(N > 9) ans = K;
    else ans = K + 100*(10-N);

    cout << ans;
    
    return 0;
}
