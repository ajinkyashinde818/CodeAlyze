#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <math.h>
#include <tuple>
#include <queue>
#include <set>

using namespace std;

int main(){
    cin.tie(0);
   	ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<long long> A(N);

    for(int i = 0; i< N;i++){
        cin >> A[i];
    }

    int cnt_minus = 0;
    for(int i = 0; i < N; i++){
        if(A[i] < 0){
            cnt_minus++;
        }
    }

    vector<long long> absA(N);
    for(int i = 0; i < N; i++){
        absA[i] = abs(A[i]);
    }


    long long ans = 0;
    if(cnt_minus % 2 == 0){
        for(int i = 0; i < N; i++){
            ans += absA[i];
        }
    }else{

        long long min_val = 0;
        min_val = *min_element(absA.begin(), absA.end());

        for(int i = 0; i < N; i++){
            ans += absA[i];
        }

        ans = ans - 2 * min_val;
    }

    cout << ans << endl;

    return 0;
}
