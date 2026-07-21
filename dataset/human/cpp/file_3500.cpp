#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

const int mod = 1000000007;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//const int dx[8] = {};
//const int dy[8] = {};

using namespace std;

template <class myType>
void p(vector<myType>& v)
{
    for(myType i: v) cout<<i<<" ";
    cout<<endl;
}

template <class myType>
void pv(vector<vector<myType>>& vv)
{
    for(auto& v: vv)
        p(v);
}

template <class myType>
void GetInputV(vector<myType>& v, int n)
{
    v.resize(n);
    for(myType& i: v) cin>>i;
}

template <class myType>
void GetInputVV(vector<vector<myType>>& vv, int m, int n)
{
    vv.resize(m);
    for(vector<myType>& v: vv) GetInputV(v, n);
}

int main()
{

    int n;
    cin>>n;
    vector<int> v;

    GetInputV(v, n);

    int negCnt = 0;
    long long res = 0;
    int mn = abs(v[0]);

    for(int i: v)
    {
        if(i <= 0) negCnt++;
        res += abs(i);
        mn = min(mn, abs(i));
    }

    if((negCnt%2) != 0)
    {
        res -= 2*mn;
    }

    cout<<res<<endl;
    

    return 0;
}
