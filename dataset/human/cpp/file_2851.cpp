#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int N;
    cin >> N;
    vector<int> A(N);
    int a;
    int min_number = -1;
    int minus_count = 0;
    ll sum_number = 0;
    for(int i=0;i<N;i++){
        cin >> a;
        if (a<0){
            minus_count++;
        }
        if(min_number==-1){
            min_number = abs(a);
        }else{
            min_number = min(min_number, abs(a));
        }
        sum_number += abs(a);
    }
    if(minus_count%2 == 1){
        sum_number -= min_number * 2;
    }
    cout << sum_number;
    return 0;
}
