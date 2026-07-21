#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <functional>
typedef long long ll;
using namespace std;
int main(){
    int n,r;
    cin >> n >> r;

    if(n >= 10)cout << r << endl;
    else{
        cout << r + 100*(10 - n) << endl;
    }
}
