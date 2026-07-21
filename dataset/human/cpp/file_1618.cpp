#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    int size = 0;
    for (int i = 1; i*i < N*2; ++i) {
        if (N*2 == i*(i+1)) {
            size = i;
            break;
        }
    }

    if (size == 0) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    cout << N*2/size << endl;
    for (int i = 0; i < N*2/size; ++i) {
        cout << size << " ";
        int tmp = i;
        int j;
        for (j = 0; j < i; ++j) {
            cout << tmp << " ";
            tmp += size-j-1;
        }
        ++tmp;
        for (; j < size; ++j) {
            cout << tmp << " ";
            ++tmp;
        }
        cout << endl;
    }



    return 0;
}
