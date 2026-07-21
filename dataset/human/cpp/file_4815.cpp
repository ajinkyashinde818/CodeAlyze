#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
 
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n,r;
    cin >> n >> r;
    if(n >= 10){
        cout << r;
    } else if(n < 10){
        int l = 100 * (10 - n);
        cout << r + l;
    }
    
    return 0;
}
