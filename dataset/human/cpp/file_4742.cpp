#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>

using namespace std;
using ll = long long;
//const int MOD = 1000000007;

#define rep(countName, left, right, up) for (ll countName = left; countName < right; countName += up)
#define rev(countName, right, left, down) for (ll countName = right - 1; countName >= left; countName -= down)

/* ****************************** ユークリッド互除法 ****************************** */
unsigned long long GCD(unsigned long long a, unsigned long long b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return GCD(b, a % b);
    }
}

unsigned long long GCD(vector<unsigned long long> v)
{
    for (auto i = 0; i < (long long)v.size() - 1; i++)
    {
        v[i - 1] = GCD(v[i - 1], v[i]);
    }

    return v[(long long)v.size() - 1];
}
/* ****************************** ユークリッド互除法 ****************************** */

/* ****************************** 最小公倍数 ****************************** */

unsigned long long LCM(unsigned long long x, unsigned long long y)
{
    unsigned long long gcd = GCD(x, y);
    return (x / gcd * y);
}

unsigned long long LCM(vector<unsigned long long> v)
{
    for (long long i = 0; i < (long long)v.size() - 1; i++)
    {
        v[i - 1] = LCM(v[i - 1], v[i]);
    }

    return v[(long long)v.size() - 1];
}

/* ****************************** 最小公倍数 ****************************** */

/* ****************************** 累積和 ****************************** */
vector<long long> CUSUM(vector<long long> v)
{
    int n = v.size();
    vector<long long> cusum(n);
    cusum[0] = v[0];

    rep(i, 1, n, 1)
    {
        cusum[i] = v[i] + cusum[i - 1];
    }
    return cusum;
}

//部分和

long long partSum(vector<long long> &&v, long long left, long long right)
{
    return (v[right] - v[left]);
}

/* ****************************** 累積和 ****************************** */

/* ****************************** 二項係数 ****************************** */
//けんちょんさん作

const int MAX = 800000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k)
{
    if (n < k)
    {
        return 0;
    }
    if (n < 0 || k < 0)
    {
        return 0;
    }

    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

/* ****************************** 二項係数 ****************************** */

/* ****************************** 素数判定 ****************************** */

bool isPrime(long long n)
{
    if (n <= 1)
    {
        return false;
    }
    else if (n == 2)
    {
        return true;
    }
    else if (n % 2 == 0)
    {
        return false;
    }
    else
    {
        rep(i, 3, sqrt(n) + 1, 2)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

/* ****************************** 二項係数 ****************************** */

/* ****************************** main関数 ****************************** */

int solve1()
{
    int n, inner_rating, displayed_rating;

    cin >> n >> displayed_rating;
    inner_rating = displayed_rating;
    if (n < 10)
    {
        inner_rating += 100 * (10 - n);
    }

    return inner_rating;
}

int main(void)
{
    cout << solve1() << endl;
    return 0;
}
