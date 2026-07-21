#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cstring>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

#define vii vector<int>
#define vll vector<ll>
#define vip vector<pair<int,int> >
#define pb push_back


int main(int argc,char* argv[])
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //#ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w",stdout);
    //#endif

    int n,r;
    cin>>n>>r;
    int ir;
    if(n>=10) ir=r;
    else ir=r+((10-n)*100);
    cout<<ir;




    return 0;
}
