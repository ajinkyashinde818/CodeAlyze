#include <iostream>
#include <cstdio>
#include <sstream>

using namespace std;

typedef unsigned int ui;

void solve(ui x) {
    int minus = x & (1U<<31);
    double ret = 0;
    for (int i = 7; i <= 30; i++) {
        if (x & (1U<<i)) {
            ret += (1<<(i-7));
        }
    }
    int last = 0;
    for (int i = 0; i < 7; i++) {
        if (x & (1U<<i)) {
            ret += (1.0 / (1<<(7-i)));
            last = max(last, (7-i));
        }
    }
    if (last == 0) last = 1;
    if (minus) {
        ret = -ret;
    }
    ostringstream fss;
    fss << "%." << last << "f\n";
    //cout << fss.str() << endl;
    printf(fss.str().c_str(), ret);
}

int main() {
    int Q; scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        ui s; scanf("%x", &s);
        solve(s);
    }
    return 0;
}
