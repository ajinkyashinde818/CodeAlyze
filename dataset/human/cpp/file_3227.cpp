#include <iostream>
//#include <iomanip>
#include <algorithm>
#include <numeric>
//#include <queue>
#include <math.h>
#include <vector>
//#include <string>
typedef long long LL;
using namespace std;

int main(){
    LL n;
    LL tmp;
    LL num=0;
    LL ans;
    vector<LL> a;
    vector<LL> a_tmp;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp;
        a.push_back(tmp);
        a_tmp.push_back(abs(tmp));
        if(tmp!=abs(tmp)){
            num++;
        }
    }
    sort(a_tmp.begin(),a_tmp.end());
    ans = accumulate(a_tmp.begin(),a_tmp.end(), 0LL);
    if(num%2!=0){
        ans -= a_tmp[0]*2;
    }
    cout << ans << endl;
}
