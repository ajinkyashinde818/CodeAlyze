#include <bits/stdc++.h>
using namespace std;
typedef long long  ll ;

long long gcd(long long aaa,long long bbb) {
    if(bbb==0) {
        return aaa;
    }
    return gcd(bbb,aaa%bbb);
}

int main (){

    int N;
    cin >> N;
    long long int a[N],sum=0,summ[N],ans=0,tmp=0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];
        summ[i] = sum;
    }

    for(int i = 0; i < N-1; i++) {
        tmp = abs(summ[i]-(sum-summ[i]));
        if(i == 0) {
            ans = tmp;
        }else {
            ans = min(ans,tmp);
        }
    }
    cout << ans << endl;

    return 0;
}
