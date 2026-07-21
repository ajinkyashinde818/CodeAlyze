#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N,R;
int main(){
    cin>>N>>R;
    if(N>=10){
        cout<<R<<endl;
    }else{
        cout<<R+100*(10-N)<<endl;
    }

    return 0;
}
