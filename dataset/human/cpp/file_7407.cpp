#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
#define endl '\n'
#define ll long long

using namespace std;

int main(void)
{
        cin.tie(NULL); ios_base::sync_with_stdio(false);
        int N; cin >> N;
        ll acc = 0;
        ll ret = LLONG_MAX;
        vector<ll> cards;

        for(int i = 0; i < N; i++)
        {
                int temp; cin >> temp; cards.push_back(temp);
                acc += temp;
        }

        ll lhs = 0;
        for(int i = 0; i < N - 1; i++)
        {
                lhs += cards[i];
                ll rhs = acc - lhs;
                ret = min(ret, abs(lhs - rhs));
        }
        cout << ret;


        return 0;
}
