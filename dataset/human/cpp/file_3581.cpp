#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int N; cin >> N;
    long long int tmp_abs=1e9,ans = 0;
    int num_minus=0;
    for (int i=0;i<N;i++){
        long long int ai; cin >> ai;
        if (ai<0) num_minus++;
        ans+=abs(ai);
        tmp_abs = min(tmp_abs,abs(ai));
    }
    if (num_minus%2==1) ans -= 2*tmp_abs;
    cout << ans << endl;
}
