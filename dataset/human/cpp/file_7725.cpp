#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, num;
    cin >> n;

    vector<long long int> a(n, 0), b(0);

    for(int i=0; i<n; i++){
        cin >> num;
        if(i==0) a[i] = num;
        else a[i] = a[i-1] + num;
    }

    long long int ans = 1e11;
    for(int i=0; i<n-1; i++){
        ans = min(ans, abs(a[i] - (a[n-1] - a[i])));
    }

    /*cout << num1 << " " << num2 << " " << ave << " " << min << endl;*/
    cout << ans << endl;
}
