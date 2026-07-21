#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <functional>

using namespace std;
#define PI 3.14159265359
#define ll long long int


int main()
{
    ll N, R, ans;
    cin >> N >> R;
    if(N >= 10) ans = R;
    else ans = R + 100 * (10 - N);

    cout << ans << endl;

    
    return 0;
}
