#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using graph = std::vector<std::vector<ll>>;

using namespace std;

int main() {
    int N,R;
    cin >> N >>R;
    if(N < 10){
        cout << R + (10 - N) * 100 << endl;
    }else{
        cout << R << endl;
    }

}
