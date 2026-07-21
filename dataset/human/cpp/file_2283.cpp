#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>
#include <set>
#include <numeric>

long long PRIME = 1e9 + 7;
long long PRIME2 = 998244353;

using namespace std;


int main(){
    long long N;
    cin >> N;

    vector<long long> A(N);
    int num_minus = 0;
    for(int i = 0; i < N; ++i){
        cin >> A.at(i);
        if(A[i] < 0){
            ++num_minus;
        }
        A[i] = abs(A[i]);
    }

    long long sum = accumulate(A.begin(), A.end(), 0LL);

    if(num_minus % 2 == 1){
        sort(A.begin(), A.end());
        sum -= 2 * A[0];
    }

    cout << sum;
}
