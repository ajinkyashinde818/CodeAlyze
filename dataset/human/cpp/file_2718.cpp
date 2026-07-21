#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main(){
    long long N;
    cin >> N;
    vector<long long> A(N);
    long long sign = 0;
    long long sum = 0;
    long long min = 1000000000;
    for(int i = 0 ; i < N ; i++){
        cin >> A[i];
        if(A[i] < 0){
            sign++;
        }
        sum += abs(A[i]);
        if(min > abs(A[i])){
            min = abs(A[i]);
        }
    }
    // long long min = *std::min_element(A.begin(), A.end());

    // cout << sum << endl;


    long long ans = 0;
    if(sign % 2 == 0){
        cout << sum << endl;
    }
    else if(sign % 2 == 1){
        cout << sum - 2 * abs(min) << endl;
    }

    return 0;
}
