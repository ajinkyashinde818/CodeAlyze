#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> vec(N);

    int count = 0;
    for(int i = 0; i < N; i++) {
        long long A;
        cin >> A;
        if(A < 0) count++;
        vec[i] = abs(A);
    }

    sort(vec.begin(), vec.end());

    if(count % 2) {
        cout << accumulate(vec.begin(), vec.end(), (long long)0) - 2 * vec[0] << endl;
    } else {
        cout << accumulate(vec.begin(), vec.end(), (long long)0) << endl;
    }
}
