#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main(void) {
    int N, ans=0;
    int R;

    cin >> N>> R;

    if(N>=10)
      ans = R;
    else
      ans = R + 100*(10-N);

    cout << ans << endl;

    return 0;
}
