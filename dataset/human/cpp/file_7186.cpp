#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <tuple>

using ll = long long;
using namespace std;



int main(){
    int N;
    cin >> N;
    ll a[N];
    ll sum = 0;
    for(int i =0; i<N; i++){
        cin >> a[i];
        sum += a[i];
    }

    ll x = 0;
    ll result = 100000000000000;

    for(int i=0; i<N-1; i++){
        x += a[i];
        ll y = sum - x;
        if(result > abs(x-y)){
            result = abs(x-y);
        }
    }

    cout << result << endl;

    return 0;
}
