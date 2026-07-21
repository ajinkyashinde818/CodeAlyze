#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<queue>
#include <climits>
#include <map>
const int mod = 1e9 + 7;
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;

int main()
{
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(n - r * i - g * j >= 0 && (n - r * i - g * j) % b == 0){
                ans++;
            }
        }
    }
    cout << ans;
}
