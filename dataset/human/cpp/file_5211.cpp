#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double PI=acos(-1.0);

int N,R;
void input()
{
    cin>>N>>R;
}

void solve()
{
    if(N>=10) cout<<R<<endl;
    else cout<<R+100*(10-N)<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}
