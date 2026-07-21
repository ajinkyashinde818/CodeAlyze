#include <bits/stdc++.h>

using namespace std;

int n, m;
string pic_a [50], pic_b [50];

bool template_match(int x, int y) {
    for (int dy = 0; dy < m; dy++) {
        for (int dx = 0; dx < m; dx++) {
            if (pic_a[y+dy][x+dx] != pic_b[dy][dx]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    bool found = false;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> pic_a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> pic_b[i];
    }

    for (int y = 0; (y <= n-m && !found) ; y++) {
        for (int x = 0; (x <= n-m && !found) ; x++) {
            found = template_match(x, y);
        }
    }

    if (found) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
