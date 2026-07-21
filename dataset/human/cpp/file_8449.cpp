#include <iostream>
#include <string>
using namespace std;

const int MAX = 50+1;

int main() {
        int n, m;
        cin >> n >> m;
        string a[MAX], b[MAX];
        for (int i=0; i<n; ++i) {
                cin >> a[i];
        }
        for (int j=0; j<m; ++j) {
                cin >> b[j];
        }

        for (int j=0; j<=n-m; ++j) {

                for (int i=0; i<=n-m; ++i) {
                        string tmp;
                        tmp = a[j].substr(i, m);
                        if (tmp.compare(b[0])==0) {
                                bool find = true;
                                for (int ii=j; ii<m+j; ++ii) {
                                        string t = a[ii].substr(i, m);
                                        if (t.compare(b[ii-j])!=0) {
                                                find = false;
                                                break;
                                        }
                                }
                                if (find) {
                                        cout << "Yes" << endl;
                                        return 0;
                                }
                        }
                }
        }
        cout << "No" << endl;
        return 0;

}
