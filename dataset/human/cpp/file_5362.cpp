#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int main(){
    int n, k;
    cin >> k >> n;
    if (k < 10)
        cout << n + 100 * (10 - k) << endl;
    else cout << n << endl;
    return 0;
}
