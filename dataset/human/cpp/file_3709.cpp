#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll INFTY = 1001001001;

int main()
{
    int N;
    cin >> N;
    int count = 0;
    ll min_v = INFTY, ans=0, a;
    for(int i=0;i<N;++i){
        cin >> a;
        if(a < 0) ++count;
        min_v = min(min_v, abs(a));
        ans += abs(a);
    }
    
    if(count % 2){
        ans -= 2 * min_v;
    }

    cout << ans << endl;
}
