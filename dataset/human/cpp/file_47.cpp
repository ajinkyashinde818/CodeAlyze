#include <bits/stdc++.h>
using namespace std;

int main()
{
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    vector<int> C = {R, G, B};
    sort(C.begin(), C.end(), greater<int>());

    int ans = 0;
    for(int i = N; i >= 0; i--)
    {
        int c1 = C.at(0) * i;
        if(c1 > N)    continue;

        for(int j = N; j >= 0; j--)
        {
            int c2 = C.at(1) * j;
            if(c1 + c2 > N)    continue;

            int c3 = N - c1 - c2;
            if(c3 % C.at(2) == 0)   ans++;
        }
    }
    cout << ans << endl;
}
