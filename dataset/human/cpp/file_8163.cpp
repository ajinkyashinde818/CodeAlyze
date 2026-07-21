#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){

    ll n;
    cin >> n;

    ll nums[n];
    ll sum = 0;

    for (int i = 0; i < n; i++){ 
        cin >> nums[i];
        sum += nums[i];
    }

    // if (n == 2){
    //     cout << nums[0] - nums[1] << endl;
    //     return 0;
    // }

    ll mn = 1e18;
    ll otherSum = 0;

    for (int i = n - 1; i > 0; i--){
        // going to have to do absolute
        
        otherSum += nums[i];
        sum -= nums[i];

        mn = min(mn, abs(sum - otherSum));
        
        // cout << " mn : " << mn << " sum : " << sum << " nums[i] : " << nums[i] << " otherSum : " << otherSum << endl;

    }

    cout << mn << endl;

    return 0; 
}
