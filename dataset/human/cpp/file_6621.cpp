#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <deque>

using namespace::std;

int ri()
{
	int x;
	scanf("%d", &x);

	return x;
}

int64_t ri64()
{
	int64_t x;
	scanf("%lld", &x);

	return x;
}

void wi(int x)
{
	printf("%d\n", x);
}

void wvi(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	printf("\n");
}

void dbg(string &str, int x)
{
	cout << str << ": ";
	wi(x);
}

void dbg(string &str, vector<int> &x)
{
	cout << str << ": ";
	wvi(x);
}

int64_t mod = 1000000007;

int main()
{
        int N = ri();
        string str;
        cin >> str;

        if (str[0] != 'B')
        {
                wi(0);
                return 0;
        }

        vector<int> A(2 * N);
        A[0] = 0;

        for (int i = 1; i < 2 * N; i++)
        {
                if (str[i] == str[i - 1])
                        A[i] = 1 - A[i - 1];
                else
                        A[i] = A[i - 1];

                //cout << i << " : " << str[i] << " " << str[i - 1] << " : " << A[i] << endl;
        }

        /*
        for (int i = 0; i < 2 * N; i++)
                cout << A[i] << " ";
        cout << endl;
        */

        bool ok = true;
        int cnt = 0;

        for (int i = 0; i < 2 * N; i++)
        {
                if (A[i] == 0)
                        cnt++;
                else
                        cnt--;

                if (cnt < 0)
                {
                        ok = false;
                        break;
                }
        }

        if (cnt != 0)
                ok = false;

        if (!ok)
        {
                wi(0);
                return 0;
        }

        int64_t ans = 1;

        cnt = 0;
        for (int i = 0; i < 2 * N; i++)
        {
                if (A[i] == 0)
                        cnt++;
                else
                {
                       ans = (ans * cnt) % mod;
                       cnt--; 
                }
        }

        for (int64_t i = 1; i <= N; i++)
                ans = (ans * i) % mod;

        wi(ans);

	return 0;
}
