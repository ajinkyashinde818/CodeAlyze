#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long num;
    long long sumA = 0;
    long long sumB = 0;
    long long Min = 9999999999;

    cin >> num;

    vector<long long> vec(num);

    for (int i = 0; i < num; i++) {
        cin >> vec.at(i);
        if (i != num - 1)
            sumA += vec.at(i);
        else
            sumB += vec.at(i);
    }

    for (int i = num - 1; i > 0; i--) {
        if (i == num - 1) {
            Min = min(Min,abs(sumA - sumB));
            continue;
        }

        sumA -= vec.at(i);
        sumB += vec.at(i);

        Min = min(Min,abs(sumA - sumB));
    }

    cout << Min;

    //
}
