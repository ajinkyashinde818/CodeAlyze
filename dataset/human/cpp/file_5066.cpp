/*
 *  * main.cpp
 *   *
 *    */

#include <bits/stdc++.h>
using namespace std;


bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}
int main() {

    int n, r;
    scanf("%d%d", &n, &r);
    if (n >= 10) printf("%d\n", r);
    else {
        printf("%d\n", r + 100 * (10 - n));
    }

    return 0;
}
