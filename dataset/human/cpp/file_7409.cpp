#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin>>n;
    long long num[n];
    long long sum=0;
    for (int i = 0; i < n; ++i) {
        cin>>num[i];
        sum+=num[i];
    }
    long long  re=1000000000000000000LL, temp;
    temp = 0;
    for (int j = 0; j < n-1; ++j) {
        temp+=num[j];
        re=min(re,abs(sum-2*temp));
    }
    cout<<re<<endl;
    return 0;
}
