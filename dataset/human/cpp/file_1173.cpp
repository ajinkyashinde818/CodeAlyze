#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int64_t count = 0;
    for (int64_t r=0; r<=3000; r++) {
        for (int64_t g=0; g<=3000; g++) {
            int64_t v = N - ((r * R) + (g * G));
            if (v >= 0 && v % B == 0) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
