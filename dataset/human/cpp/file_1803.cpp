#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    reverse(v.begin(), v.end());
    for(int i=0; i<m; ++i) {
        int q;
        cin >> q;
        v.push_back(q);
    }
    set<int> s;
    for(int i=v.size()-1; s.size() < n; --i) {
        if(s.count(v[i]) == 0) {
            cout << v[i] << endl;
        }
        s.insert(v[i]);
    }
}
