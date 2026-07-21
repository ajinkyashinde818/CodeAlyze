#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main(){

    ll n;
    cin >> n;

    vector<ll> nums(n);

    bool zero = false;

    ll zeroSum = 0;
    ll mn = 1e9+7; 
    ll minusCnt = 0;

    for (int i = 0; i < n; i++){
        cin >> nums[i];
        if (nums[i] < 0) minusCnt++;
        mn = min(abs(nums[i]), mn);
        if (!nums[i]) zero = true;
        zeroSum += abs(nums[i]);
    }

    if (zero){
        cout << zeroSum << endl;
    }
    else if (minusCnt % 2 == 0){
        cout << zeroSum << endl;
    }
    else {
        cout << zeroSum - (mn * 2) << endl;
    }

    return 0;
}
