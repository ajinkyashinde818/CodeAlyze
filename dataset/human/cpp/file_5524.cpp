#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <set>
#include <cmath>
#include <array>
#include <bitset>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<n+1;i++)
int main(){
    int N,R;
    cin>>N>>R;
    int ans;
    if(N>=10)cout<<R;
    else{
        cout<<R+100*(10-N);
    }
    return 0;
}
