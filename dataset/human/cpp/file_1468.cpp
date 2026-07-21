#include <queue>
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    int n; cin >> n;
    if (n == 1) { cout << "Yes\n2\n1 1\n1 1\n"; return 0; }
    int k = 2;
    while (k * (k+1) / 2 < n) k++;
    if (k * (k+1) / 2 > n) {cout << "No\n"; return 0;}
    cout << "Yes\n" << k+1 << endl;
    queue<int> q[k+1];
    int cnt = 1;
    for (int j = 0; j <= k; j++) {
        cout << k << ' ';
        for (int m = 0; m < j; m++) {
            cout << q[m].front() << ' ';
            q[m].pop();
        }
        for (int m = j; m < k; m++) {
            cout << cnt << ' ';
            q[j].push(cnt);
            cnt++;
        }
        cout << endl;
    }
}
