#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int l = 0;
    vector<int> a(1e+5);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] <= 0)
        {
            l += 1;
        }
    }

    // 偶x偶 or 偶x奇
    long sum = 0;
    if (l % 2 == 0){
        for (int i = 0; i < n; i++)
        {
            sum += abs(a[i]);
        }
    } else{
        // 奇x偶
        // 奇x奇
        int m = abs(a[0]);
        for (int i = 0; i < n; i++)
        {
            sum += abs(a[i]);
            if (m >= abs(a[i])){
                m = abs(a[i]);
            }
        }
        sum -= (2 * m);
    }

    cout << sum;
    return 0;
}
