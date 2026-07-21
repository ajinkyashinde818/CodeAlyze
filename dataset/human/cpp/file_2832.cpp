#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main()
{

    long long n, ans = 0, min = 1000000001, flag = 0;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
        if(a[i] < 0){
            flag++;
        }
        if(min > abs(a[i])){
            min = abs(a[i]);
        }
    }

    if(flag % 2 == 0){
        for(int i = 0;i < n;i++){
            if(a[i] < 0){
                ans += -a[i];
            }
            else{
                ans += a[i];
            }
        }
    }
    else{
        for(int i = 0;i < n;i++){
            if(a[i] < 0){
                ans += -a[i];
            }
            else{
                ans += a[i];
            }
        }

        ans -= min * 2;
    }



    cout << ans;

    return 0;

}
