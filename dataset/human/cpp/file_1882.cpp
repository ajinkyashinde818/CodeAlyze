#include <bits/stdc++.h>

using namespace std;

int etot(char a) {
    if(a >= 'a') {
        return a - 'a' + 10;
    } else {
        return a - '0';
    }
}

int main() {
    
    int q;
    string s;

    cin >> q;

    for(int k = 0; k < q; ++k) {

        cin >> s;

        unsigned int b = 0;
        for(int i = 0; i < 8; ++i) {
            b |= etot(s[7 - i]) << 4 * i;
        }

        if(b >> 31 & 1) cout << "-";

        cout << ((b >> 7) & ((1 << 24) - 1));

        int under_point = 0;
        int w = 78125;
        for(int i = 0; i < 7; ++i) {
            if((b >> i) & 1) {
                under_point += w;
            }
            w *= 2;
        }

        cout << ".";

        if(under_point) {
            int d = 7;
            while(!(under_point % 10)) {
                under_point /= 10;
                --d;
            }
            printf("%0*d\n", d, under_point);
        } else {
            cout << "0" << endl;
        }

    }

}
