#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    int cnt = 0;
    long long kekka = 0;
    cin >> num;

    vector<long long> vec(num);
    for (int i = 0; i < num; i++) {
        long long tmp;
        cin >> tmp;

        if (tmp < 0) cnt++;
        vec.at(i) = tmp;
    }

    sort(vec.begin(), vec.end());
    if (cnt % 2 == 0) {
        for (int i = 0; i < num; i++) {
            kekka += abs(vec.at(i));
        }
    } else {
        for (int i = 0; i < cnt-1; i++) {
            kekka += abs(vec.at(i));
        }

        if(cnt == num){
            kekka += vec.at(num - 1);
        } else {
            if (abs(vec.at(cnt - 1)) > abs(vec.at(cnt))) {
            vec.at(cnt - 1) *= -1;
            vec.at(cnt) *= -1;
        }
        for (int i = cnt - 1; i < num; i++) {
            kekka += vec.at(i);
        }
        }
    }

    cout << kekka << endl;

    //
}
