#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    long long N;
    cin >> N;
    vector<long long> nums(N);
    for(int i = 0; i < N; i++) cin >> nums[i];
    
    long long mcnt = 0;
    for(int i = 0; i < N; i++)
    {
        if (nums[i] < 0) mcnt++;
    }
    
    long long ans = 0;
    if (mcnt % 2 == 0)
    {
        for(int i = 0; i < N; i++)
        {
            if (nums[i] < 0) nums[i] *= -1;
            ans += nums[i];
        }
    }
    else
    {
        long long mnum = 100000000000;
        for(int i = 0; i < N; i++)
        {
            long long num = abs(nums[i]);
            mnum = min(mnum, num);
        }
        
        for(int i = 0; i < N; i++)
        {
            if (abs(nums[i]) == mnum)
            {
                ans -= mnum;
            }
            else
            {
                ans += abs(nums[i]);
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
