#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;  cin >> n;
    int mini = (int)(1e9+1);
    long long int ans = 0;
    int count = 0;
    for (int i=0; i<n; i++){
        int m;  cin >> m;
        mini = min(mini, abs(m));
        ans += abs(m);
        if (m < 0)  count++;
    }

    if (count%2 == 1)  ans -= 2*mini;

    cout << ans << endl;

    return 0;
}
