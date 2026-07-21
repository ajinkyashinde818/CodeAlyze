/*
    Created by 10_months
    Tag:
    Link:
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
                
using namespace std;

const long long inf = 1e17;
const int INF = 1e9;
const int N = 1234567;
const int M = 123456;

int n, m;
string a[N], b[N];
                         
int main() {
    #ifdef home
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    int good = 0;                      
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {    
            int diff = 0;
            for (int l = 0; l < m; l++)
                for (int k = 0; k < m; k++)
                    if (a[i + l][j + k] != b[l][k]) diff++;
        if (diff == 0) good = 1;                        
        }
    puts(good ? "Yes" : "No");
    return 0;
}
