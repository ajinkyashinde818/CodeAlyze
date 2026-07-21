#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iomanip>
#include <cstdio>
#include <float.h>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <stack>
#include <functional>
       
using namespace std;
       
#define endl '\n'
#define MOD 1000000007
#define INF 1ll<<30
 
// #define MAX 100010
 
#define eps 1e-11
#define bit_max 1ll<<32
#define _USE_MATH_DEFINES


int n,m;
int zz[30];
long long int total_sum = -1;
long long int ans = -1;
void solve(int a,int b,int c)
{
    if(a>n)
        return;
    if(a>total_sum)
    {
        total_sum = a;
        ans = b;
    }
    if(c>=m)
        return;
    solve(a+zz[c],b|(1<<c),c+1);
    solve(a,b,c+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    // #endif
    int n,m;
    cin>>n>>m;
    char a[n][n];
    char b[m][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            char c;
            cin>>c;
            a[i][j]=c;
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>b[i][j];
        }
    }
    bool poss = false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int c= 0;
            if(a[i][j]==b[0][0])
            {
                for(int k=0;k<m;k++)
                {
                    for(int l=0;l<m;l++)
                    {
                        if(i+k>=n||j+l>=n)
                            break;
                        if(b[k][l]==a[i+k][j+l])
                            c++;
                    }
                    if(i+k>=n)
                        break;
                }
            }
            if(c==m*m)
                poss = true;
            if(poss)
                break;
        }
        if(poss)
            break;
    }
    if(poss)
        cout<<"Yes";
    else
        cout<<"No";
    cout<<endl;
    return 0;
}
