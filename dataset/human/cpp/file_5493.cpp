#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <map>
#include <iomanip>
#include <limits.h>

using namespace std;    
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
const bool DEBUG = true;

int main(){

    int n, r;
    cin >> n >> r;

    if(n >= 10){
        cout << r << endl;
    }
    else{
        cout << r + 100 * (10 - n) << endl;
    }

}
