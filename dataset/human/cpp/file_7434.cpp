#include <iostream>
#include <vector>
#include <algorithm>

long long int abs(long long x, long long y)
{
    if(x>=y) return (x-y);
    else return (y-x);
}

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long int> a(n);
    int temp;
    cin >> temp;
    a[0] = temp;
    for(int i=1; i<n; i++)
    {
        cin >> temp;
        a[i] = a[i-1] + temp;
    }

    long long int sum = a[n-1];
    long long int min = abs(2*a[0],sum);
    //cout << sum << "\n";

    long long int temps;
    int m = n-1;
    for(int i=0; i<m; i++)
    {
        temps = abs(2*a[i], sum);
        //cout << temps << "\n";
        if(temps < min) min = temps;
    }

    cout << min << endl;

    return 0;
}
