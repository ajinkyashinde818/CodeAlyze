#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];

    long long ans[n-1];
    ans[0] = 0;
    long long max;
    for(int i=1;i<n;i++)ans[0] += a[i];
    max = ans[0] + a[0];

    for(int i=1;i<n-1;i++)ans[i] = ans[i-1] - a[i];

    for(int i=0;i<n-1;i++)ans[i] = abs(2*ans[i] - max);

    long long res = ans[0];
    for(int i=1;i<n-1;i++){
        if(ans[i]<res)res = ans[i];
    }

    cout << res << endl;

}
