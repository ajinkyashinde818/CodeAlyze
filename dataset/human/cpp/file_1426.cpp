#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > construct(int k) {
    vector< vector<int> > ret(k);

    int num = 1;
    for(int i=0;i<k-1;++i) {
        for(int j=i+1;j<k;++j) {
            ret[i].push_back(num);
            ret[j].push_back(num);
            ++num;
        }
    }

    return ret;
}

int main() {
    int n;
    cin >> n;

    if(n == 1) {
        cout << "Yes\n2\n1 1\n1 1\n";
        return 0;
    }

    for(int k=3;k<=447;++k) {
        if(k*(k-1)/2 == n) {
            vector< vector<int> > ans = construct(k);
            cout << "Yes\n" << k << "\n";
            int m = 2*n/k;
            for(vector<int> s: ans) {
                cout << m;
                for(int x: s) {
                    cout << " " << x;
                }
                cout << "\n";
            }
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}
