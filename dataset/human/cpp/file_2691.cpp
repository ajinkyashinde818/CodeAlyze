#include<iostream>
#include<cstring>
#include<math.h>
#include<algorithm>

using namespace std;



int main(){

    long long n;
    cin >> n;

    long long a[n];
    for(long long i=0;i<n;i++)cin >> a[i];

    long long minus = 0;
    for(long long i=0;i<n;i++){
        if(a[i]<0)minus++;
    }
    long long ans = 0;
    for(long long i=0;i<n;i++){
        if(a[i]<0)a[i] = -a[i];
    }
    sort(a, a+n);
    for(long long i=0;i<n;i++){
        ans += a[i];
    }
    if(minus%2==1)ans -= 2*a[0];

    cout << ans << endl;

}
