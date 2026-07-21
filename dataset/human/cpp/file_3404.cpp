#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long sum = 0;
    int cnt = 0;
    int minNum = 1000000000 + 1;
    for(int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        if(t < 0) ++cnt;
        int abst = abs(t);
        if(abst < minNum) minNum = abst;
        sum += abst;
    }
    if(cnt%2!=0) sum -= 2*minNum;
    cout << sum << endl;
}
