#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int row1, col1, row2, col2;

    cin >> row1 >> row2;

    col1 = row1;
    col2 = row2;

    vector<string> vec(row1);
    vector<string> vec2(row2);

    for (int i = 0; i < row1; i++) cin >> vec.at(i);
    for (int i = 0; i < row2; i++) cin >> vec2.at(i);

    for (int i = 0; i <= row1 - row2; i++) {
        for (int j = 0; j <= col1 - col2; j++) {
            bool okFlg = true;
            for (int k = 0; k < row2; k++) {
                string tmp1, tmp2;
                tmp1 = vec.at(i+k);
                tmp2 = vec2.at(k);
                //cout << tmp1.substr(j, row2) << ":::" << tmp2 << endl;
                if (tmp1.substr(j, row2) != tmp2) {
                    okFlg = false;
                    break;
                }
            }

            if (okFlg == true) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    //
}
