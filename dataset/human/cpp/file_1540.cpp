#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <cmath>
#include <limits.h>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <stdio.h>
using namespace std;

long long MOD = 1000000007;

int main() {
    
    int N;
    cin >> N;

    if ( N == 1 ) {
        cout << "Yes" << endl;
        cout << 2 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    long long z;
    for ( long long i = 3; i < 1000; i++ ) {
        long  long a = i*(i-1)/2;
        if ( a > N ) { cout << "No" << endl; return 0; }
        if ( a == N ) { z = i; cout << "Yes" << endl; break; }
    }
    cout << z << endl;

    vector< vector<int> > A(z);
    long long x = 1;
    for ( long long a = 0; a < z; a++ ) {
    for ( long long b = a+1; b < z; b++ ) {
        A[a].push_back(x);
        A[b].push_back(x);
        x++;
    }
    }

    for ( int i = 0; i < z; i++ ) {
        cout << A[i].size() << " ";
        for ( int j = 0; j < A[i].size(); j++ ) {
            cout << A[i][j];
            if ( j != A[i].size()-1 ) { cout << " "; }
        }
        cout << endl;
    }



    return 0;
}
