#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

int main(){

    int N;
    cin >> N;

    vector<long long> num(N);
    long long cnt = 0;
    long long absMin = 10000000000;
    for(int i = 0; i < N; i++){
        cin >> num[i];
        if(num[i] < 0) cnt ++;
        num[i] = abs(num[i]);
    }
    sort(num.begin(), num.end() );
    if(cnt % 2 == 1){
        cout << accumulate(num.begin(), num.end(), 0ll) - 2 * num[0] << endl;
    }
    else{
        cout << accumulate(num.begin(), num.end(), 0ll)  << endl;
    }


}
