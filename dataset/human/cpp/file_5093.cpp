#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int N , R;
    cin >> N >> R;
    if(N < 10){
        cout << R + 100 * (10 - N);
        return 0;
    }
    else{
         cout << R;
         return 0;
    }
}
