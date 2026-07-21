#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> a, b;
int n, m;

bool check(int h, int w) {
    if (h+m-1 >= n || w+m-1 >= n)
        return false;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (a[h+i][w+j] != b[i][j])
                return false;
        }
    }

    return true;
}

int main() {
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check(i, j)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
