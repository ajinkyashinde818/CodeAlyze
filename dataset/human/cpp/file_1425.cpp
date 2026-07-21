#include<iostream>
#include<vector>

using namespace std;
int n;
vector<vector<int>> S;

int main() {
    cin >> n;
    int k = 2;
    int nc = 1;
    S.push_back(vector<int>({1}));
    S.push_back(vector<int>({1}));
    bool ok = true;
    while (nc < n) {
        S.push_back(vector<int>());
        for (int i = 0; i < k; ++i) {
            S[i].push_back(nc + i + 1);
            S[k].push_back(nc + i + 1);
        }
        nc+=k;
        k++;
        //cout << nc << endl;
        if (nc == n) {
            break;
        }
        if (nc > n) {
            ok = false;
            break;
        }
    }
    if (ok) {
        cout << "Yes" << endl;
        cout << S.size() << endl;
        for (vector<int> si : S) {
            cout << si.size();
            for (int sij : si) {
                cout << " " << sij;
            }
            cout << endl;
        }
    } else {
        cout << "No" << endl;
    }
}
