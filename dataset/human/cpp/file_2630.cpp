#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin >> a[i];
        
    sort(a.begin(), a.end());

    int64_t sum = 0;

    for(int i=0;i<n-1;i=i+2)
    {
        if(a[i] <= 0 && a[i+1] <= 0)
            sum += -a[i] - a[i+1];
        else if(a[i] <= 0 && a[i+1] > 0)
        {
            if(-a[i] > a[i+1])
                sum += -a[i] - a[i+1];
            else
                sum += a[i] + a[i+1];
        }
        else
            sum += a[i] + a[i+1];
    }

    if(n % 2 != 0)
        sum += a[n-1];

    cout << sum << endl;
    return 0;
}
