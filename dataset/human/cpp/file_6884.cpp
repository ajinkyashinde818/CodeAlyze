#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> b[i];
    }

    reverse(b.begin(), b.end());
    int c = -1, l = 0, r = N-1;
    for (int i = 0; i < N; ++i) {
        if (a[i] == b[i]) {
            c = b[i];
            l = i;
            break;
        }
    }

    if (c == -1) {
        cout << "Yes" << endl;
        copy(b.begin(), b.end(), ostream_iterator<int>(cout, " "));
        return 0;
    }

    for (int i = N-1; i >= 0; --i) {
        if (a[i] == c && b[i] == c) {
            r = i;
            break;
        }  
    }

    for (int i = 0; i < N; ++i) {
        if (a[i] != c && b[i] != c && l <= r) {
            swap(b[i],b[l]);
            ++l;
        }
    }

    if (l <= r) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        copy(b.begin(), b.end(), ostream_iterator<int>(cout, " "));
    }
}
