#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ll N;
    string S;
    cin >> N >> S;
    map<char, ll> cSet;
    for(auto s : S){
        if(cSet.count(s)==0) cSet[s]=0;
        cSet[s]++;
    }
    ll sum = 1;
    for(auto c : cSet){
        if(c.second==1){
            sum *= 2;
        }else{
            sum *= (c.second+1);
        }
        sum %= 1000000007;
    }
    sum -= 1;
    cout<<sum<<endl;

    return 0;
}
