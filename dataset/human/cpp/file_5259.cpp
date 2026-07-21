#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <cfloat>
#include <math.h>
#include <numeric>
#include <string.h>
#include <sys/time.h>
#include <random>


#define fs first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;


int main(){
    int n, r;   cin >> n >> r;
    if(n >= 10){
        cout << r << endl;
    }
    else{
        cout << r + 100 * (10 - n) << endl;
    }


    return 0;
}
