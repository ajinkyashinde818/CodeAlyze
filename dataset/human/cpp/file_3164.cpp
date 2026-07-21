#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<ll> nums(N);
    int minusCount = 0;
    for(int i = 0; i < N; i++)
    {
       ll num;
       cin >> num;
       if(num < 0){
           minusCount++;
           num *= -1;
       }
       nums.at(i) = num;
    }
    if(minusCount % 2 == 1){
        sort(nums.begin(), nums.end());
        nums.at(0) *= -1;
    }
    cout << accumulate(nums.begin(), nums.end(), (ll)0) << endl;
    return 0;
}
