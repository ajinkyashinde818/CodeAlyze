#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    long long sum=0,m=1000000000;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        long long a;
        cin >> a;
        if(a<0)
        {
            a=-a;
            cnt++;
        }
        sum+=a;
        m=min(m,a);
    }
    if(cnt&1) cout << sum-2*m << endl;
    else cout << sum << endl;
    return 0;
}
