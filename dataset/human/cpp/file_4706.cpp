#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <cstring>
#include <queue>
using namespace std;

int main(){
    int n, r;
    cin >> n >> r;
    if(n >= 10) cout << r << '\n';
    else {
        cout << (r + 100*(10 - n)) << '\n';
    }
}
