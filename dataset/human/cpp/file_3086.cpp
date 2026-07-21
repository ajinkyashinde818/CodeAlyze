#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> vec(N);

    // マイナスの数値の出現回数
    int minus_num = 0;
    // 絶対値の合計値
    long long sum = 0;

    for(int i=0; i < N; i++) {
        long long tmp;
        cin >> tmp;
        
        if(tmp < 0) minus_num++;

        vec.at(i) = abs(tmp);
        sum += vec.at(i);
    }

    if(minus_num % 2 != 0) {
        sort(vec.begin(), vec.end());
        sum -= vec.at(0) * 2;
    }

    cout << sum << endl;

    return 0;
}
