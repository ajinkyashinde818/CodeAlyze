#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main() {
    long long n, r;
    cin >> n >> r;
    if(n > 10) {
        cout << r << "\n";
    } else {
        cout << r + (100 * (10 - n)) << "\n";
    }
}
