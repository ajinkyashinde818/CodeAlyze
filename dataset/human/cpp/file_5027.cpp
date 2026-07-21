#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include<stack>
#include<string>
#include<algorithm> 
#include <set>
#include<list>
#include <bit>
#include <bitset>
#include <cstdint>
#include <initializer_list>
using namespace std;
int main() {
    int N, R; cin >> N >> R;
    if (N >= 10)cout << R << endl;
    else {
        cout << R + 100 * (10 - N) << endl;
    }
    return 0;
}
