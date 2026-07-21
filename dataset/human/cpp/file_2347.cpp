#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main()
{
    int n, mns = 0;
    long long s = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(a[i] < 0) ++mns;
        a[i] = abs(a[i]);
        s += a[i];
    }
    if(mns % 2 == 0){
        cout << s << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    cout << s - a[0]*2 << endl;
    return 0;
}
