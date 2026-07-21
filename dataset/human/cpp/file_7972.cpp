#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[200001];
    ll s[200001] {0};
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    s[0] = a[0];
    for(int i = 0; i < n - 1; i++){
        s[i + 1] = s[i] + a[i + 1];
    }
    ll all = s[n - 1];
    sort(s, s + n - 1);
    for(int i = 0; i < n; i++){
    }
    int mid = lower_bound(s, s + n - 1, all / 2) - s;
    if(mid == n - 1){
        cout << abs(s[n - 2] - (all - s[n - 2])) << endl;
    }
    else if(mid == 0){
        cout << abs(s[0] - (all - s[0])) << endl;
    }   
    else{
        cout << min(abs(s[mid] - (all - s[mid])), abs(s[mid - 1] - (all - s[mid - 1]))) << endl;
    }
}
