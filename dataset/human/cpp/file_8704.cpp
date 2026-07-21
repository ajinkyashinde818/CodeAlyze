#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(n));
    vector<vector<char>> b(m, vector<char>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> a.at(i).at(j);
        }
    }
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> b.at(i).at(j);
        }
    }

    bool exist = false;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i+m-1 >= n || j+m-1 >= n) {
                continue;
            }else {
                int flgin = 0;
                for(int k = 0; k < m; ++k) {
                    for(int l = 0; l < m; ++l) {
                        if(a.at(i+k).at(j+l) != b.at(k).at(l)) {
                            flgin = 1;
                        }
                    }
                }
                if(flgin == 0) exist = true;
            }
        }
    }

    if(exist) {
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
}
