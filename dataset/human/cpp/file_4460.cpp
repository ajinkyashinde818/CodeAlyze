#include<iostream>
using namespace std;
int n, m;
int main() {
    cin >> n >> m;
    if (n % 2 == 0) {
        for (int i = 0; i < n / 2 + 1; i++) { if (i)cout << ' '; cout << "0"; }
        for (int i = 0; i < n / 2 - 1; i++)cout << ' ' << m;
    }
    else {
        for (int i = 0; i < n / 2 + 1; i++) { if (i)cout << ' '; cout << "0"; }
        for (int i = 0; i < n / 2; i++)cout << ' ' << m;
    }
    cout << endl;
    return 0;
}
