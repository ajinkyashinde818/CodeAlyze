#include<iostream>
#include<string>
using namespace std;
const int BUF = 55;


int szA, szB;
string A[BUF], B[BUF];

void read() {
    cin >> szA >> szB;
    for (int i = 0; i < szA; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < szB; ++i) {
        cin >> B[i];
    }
}


void work() {
    for (int ar = 0; ar + szB <= szA; ++ar)
        for (int ac = 0; ac + szB <= szA; ++ac) {
            for (int br = 0; br < szB; ++br) {
                for (int bc = 0; bc < szB; ++bc) {
                    if (A[ar + br][ac + bc] != B[br][bc]) {
                        goto _fail;
                    }
                }
            }
            cout << "Yes" << endl;
            return;
            _fail:;
        }
    cout << "No" << endl;
}


int main() {
    read();
    work();
    return 0;
}
