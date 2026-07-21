#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

using lli = long long int;

int main() {
    int n;

    cin >> n;

    vector<lli> v(n);
    vector<pair<lli, lli>> sumPair(n - 1);  //i番目の要素まで左に取ったときの和

    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];

        if(i == 0)
        {
            sumPair[0].first = v[i];
        }
        else
        {
            sumPair[0].second += v[i];
        }
    }

    lli minDiff = abs(sumPair[0].first - sumPair[0].second);
    

    for(int i = 1; i < n - 1; ++i)
    {
        sumPair[i].first = sumPair[i - 1].first + v[i];
        sumPair[i].second = sumPair[i - 1].second - v[i];

        lli diff = abs(sumPair[i].first - sumPair[i].second);

        if(diff < minDiff)
        {
            minDiff = diff;
        }
    }

    cout << minDiff << endl;
    
    return 0;
}
