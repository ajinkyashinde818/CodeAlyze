#include<iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    long long a[n];

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    long long mini = 10000000000;
    long long acm = 0;
    for (int i = 0; i < n - 1; i++) {
        acm += a[i];
        mini = min(mini, abs(sum - 2 * acm));
        //cout << abs(sum - 2 * acm) << endl;
    }

    cout << mini << endl;
}
