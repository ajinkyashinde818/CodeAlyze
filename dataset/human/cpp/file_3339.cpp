#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    int N;
    cin >> N;
    int tmp;
    long dp0 = 0;
    long dp0dummy;
    long dp1 =  -1000000001;
    long dp1dummy;

    for(int i = 0; i < N; i++){
        cin >> tmp;
        dp0dummy = dp0;
        dp1dummy = dp1;
        dp0 = max(dp0dummy+tmp, dp1dummy-tmp);
        dp1 = max(dp0dummy-tmp, dp1dummy+tmp);
    }

    cout << dp0 << '\n';

    return 0;
}
