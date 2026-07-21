#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <deque>
#include <map>

using namespace std;

const int CMax = 100002;
const int CInf = 2000000001;
const long long CMod = 1000000007;

int n, A[CMax];

int gcd(int a, int b)
{
    if (b != 0) return gcd(b, a % b);
    else return a;
}

string baseConverter(int base, int num) {
    string tNum = "";
    while (num > 0) {
        tNum = (char)('0' + num%base) + tNum;
        num /= base;
    }
}

bool isPalindrom(string tS) {
    int sn = (int)tS.length();
    for (int i = 0; i < sn / 2; i++) {
        if (tS[i] != tS[sn - i - 1]) return false;
    }
    return true;
}

int dist(int i, int j) {
    return  (j < i ? n + j : j) - i;
}

int main()
{
    cin >> n;

    int neg = 0, minNum = CInf;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] < 0) neg++;
        res += (long long)abs(A[i]);
        minNum = min(minNum, abs(A[i]));
    }

    if (neg % 2 > 0) res -= (long long)(minNum * 2);

    cout << res;

    cout << endl;

    return 0;
}
