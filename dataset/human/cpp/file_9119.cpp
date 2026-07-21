#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <sstream>
#include <limits>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define PI (acos(-1.0))
#define Abs(a) (((a)<0) ? (-(a)) :(a) )
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define Rep(i,n) for(int i=0;i<(n);i++)
#define Rrep(i,n) for(int i=((n)-1);i>=0;i--)
#define rrep(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define Pii pair<int,int>
#define PB push_back
#define Size(x) ((int)(x.size()))
using namespace std;
typedef long long mint;
typedef unsigned long long umint;
string a[55], b[55];
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    cin >> n >> m;
    Rep(i,n)
    {
        cin >> a[i];
    }
    Rep(i,m)
    {
        cin>> b[i];
    }
    Rep(p, n - m + 1)
    {
        Rep(q, n - m + 1)
        {
            bool ok = true;
            Rep(r, m)
            {
                Rep(s, m)
                {
                    if(a[p + r][q + s] != b[r][s])
                    {
                        ok = false;
                        break;
                    }
                }
                if(!ok)
                {
                    break;
                }
            }
            if(ok)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
