#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define ll long long
#define imfor(i, n) for(int i = 0; i < n; i++)
using namespace std;
ll MOD = 1000000007;

int main() {
    int n, m;
    char a[60][60], b[60][60];
    cin >> n >> m;
    imfor(i, n) {
        imfor(j, n) {
            cin >> a[i][j];
        }
    }
    imfor(i, m) {
        imfor(j, m) {
            cin >> b[i][j];
        }
    }
    int ex = 0;
    imfor(i, n) {
        imfor(j, n) {
            if (i + m - 1 >= n || j + m - 1 >= n) {
                continue;
            }
            int f = 1;
            imfor(k, m) {
                imfor(l, m) {
                    if (a[k + i][l + j] != b[k][l]) {
                        f = 0;
                    }
                }
            }
            if (f == 1) {
                ex = 1;
            }
        }
    }
    if (ex == 1) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
