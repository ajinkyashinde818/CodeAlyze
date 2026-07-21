#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<utility>
#include<cstring>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const int maxn= 1e5+10;
const int mod =1e9+7;
const double EPS = 1e-6;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,r;
    cin >> n >> r;
    if(n>=10)
        cout << r << endl;
    else
    {
        cout << r+100*(10-n) << endl;
    }
    return 0;
}
