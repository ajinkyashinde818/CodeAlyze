#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<long long int> VI;

int main(void) {
    long long int n;
    cin >> n;
    VI a(n);
    long long int total = 0;
    for (long long int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    long long int div;
    long long int left = 0;
    long long int right = total;
    for (long long int i = 0; i < n - 1; i++) {
        left += a[i];
        right -= a[i];
        //cout << left << " " << right << endl;

        long long int temp = right - left;
        if (temp < 0) {
            temp *= (-1);
        }
        if (i == 0) {
            div = temp;
        } else {
            div = min(temp, div);
        }

    }
    cout << div << endl;
    return 0;
}
