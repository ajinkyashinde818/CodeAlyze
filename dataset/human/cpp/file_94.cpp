#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
template <typename T = int>
T in() {
    T temp; cin >> temp; return temp;
}

template <typename VType = int>
list<VType> const LR(VType start, VType end) {
    list<VType> ret; for (VType i = start; i < end; i++) ret.push_back(i); return move(ret);
}

int main() {
    int const R(in()), G(in()), B(in()), N(in());
    int ret = 0;

    for (size_t i = 0; i <= N/R; i++) {
        int remain = N - i*R; 
        for (int j = 0; j <= remain / G; j++) {
            int remain2 = remain - j * G;
            if (0 == (remain2 % B)) ret++;
        }
    }

    cout << ret << endl; 
    return 0;
}
