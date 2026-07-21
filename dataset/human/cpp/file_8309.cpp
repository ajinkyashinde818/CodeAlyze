#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, m;

int is_matched(const vector<string> _a, const vector<string> _b, int _i, int _j) {
    for (int k=0; k<m; k++) {
        for (int l=0; l<m; l++) {
            if (_a[_i+k][_j+l] != _b[k][l])
                return 0;
        }
    }

    return 1;
}

int matching(const vector<string> _a, const vector<string> _b) {
    for (int i=0; i<n-m+1; i++) {
        for (int j=0; j<n-m+1; j++) {
            if (is_matched(_a, _b, i, j))
                return 1;
        }
    }

    return 0;
}



int main()
{
    scanf("%d %d", &n, &m);

    vector<string> a;
    for (int i=0; i<n; i++) {
        string input;
        cin >> input;
        a.push_back(input);
    }

    vector<string> b;
    for (int j=0; j<m; j++) {
        string input;
        cin >> input;
        b.push_back(input);
    }

    if (matching(a, b)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
