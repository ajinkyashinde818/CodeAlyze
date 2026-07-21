#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

#define INF  -10000000000

int main()
{
    int n;
    int r,g,b;
    
    cin >> r >> g >> b >> n;
    
    long long ans = 0;
    
    for (int i = 0;i <= n/r;i++){
        for (int j = 0;j <= n/g;j++){
            if (i*r+j*g <= n && (n-i*r-j*g)%b == 0){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
