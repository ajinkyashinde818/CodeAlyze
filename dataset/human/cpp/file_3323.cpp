#include <algorithm>
#include <iostream> //入出力
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <math.h> //算術演算子
#include <vector>
#include <cstdlib>
#include <queue>
#include <stack>
#include <list>
#include <iomanip> //小数点以下を表示させる(setprecision())
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //64bit型

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define debug(x) cerr << x << " " \
                      << "(L:" << __LINE__ << ")" << '\n'
#define PRINT(V)                                   \
        {                                          \
                for (int i = 0; i < V.size(); i++) \
                {                                  \
                        cout << V[i] << " ";       \
                }                                  \
                cout << endl;                      \
        }

int gcd(int a, int b)
{
        return b ? gcd(b, a % b) : a;
}

int main()
{
        //input->compute->output//

        int N;
        cin >> N;
        vector<int> A(N);
        int cnt = 0;
        ll ans = 0;
        int m = (int)1e9 + 10;
        for (int i = 0; i < N; i++)
        {
                cin >> A[i];
                if (A[i] < 0)
                {
                        cnt++;
                }

                m = min(abs(A[i]), abs(m));
                ans += abs(A[i]);
        }

        if (cnt % 2 == 0)
        {
                cout << ans << endl;
        }
        else
        {
                cout << ans - 2 * m << endl;
        }

        return 0;
}
