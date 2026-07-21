#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b(m);
    for(int i = 0;i < n;i++) {
        cin >> a.at(i);
    }
    for(int i = 0;i < m;i++) {
        cin >> b.at(i);
    }
    bool exist = false;
    for(int i_a = 0;i_a < n;i_a++){
        for(int j_a = 0;j_a < n;j_a++){
            if(i_a + m - 1 >= n || j_a + m - 1 >= n) {
                continue;
            }
            bool match = true;
            for(int i_b = 0;i_b < m;i_b++){
                for(int j_b = 0;j_b < m;j_b++){
                    if(a.at(i_a + i_b).at(j_a + j_b) != b.at(i_b).at(j_b)) {
                        match = false;
                    }
                }
            }
            if(match) {
                exist = true;
            }
        }
    }
    if(exist)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
