#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N ;

    vector<long long int> A;
    long long int tmp;
    long long int sum = 0;
    int count = 0;
    for (int i = 0; i<N; i++) {
        cin >> tmp;
        if (tmp < 0) {
            count++;
        }
        A.push_back(abs(tmp));
        sum += abs(tmp);
    }

    sort(A.begin(), A.end());

    if (count % 2 == 1) {
        sum -= A[0]*2;
    }

    cout << sum << endl;

    return 0;
}
