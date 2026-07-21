#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

int main(void){
    long n, neg_num, ans;

    cin >> n;

    vector<long> a(n), b(n);


    neg_num = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        b[i] = abs(a[i]);
        if(a[i] < 0)    neg_num++;
    }

    ans = 0;
    if(neg_num % 2){
        sort(b.begin(), b.end());
        b[0] = -1 * b[0];
        for(int i = 0;i < n;i++)    ans += b[i];
        cout << ans << endl;

    }else{
        for(int i = 0;i < n;i++)    ans += b[i];
        cout << ans << endl;
    }


    return 0;
}
