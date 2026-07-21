#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <set>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define drep(i, n) for(int i = n - 1; i >= 0; i--)
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define yes cout << "yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define no cout << "no" << endl
#define PI 3.14159265359

const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const int mod = 1000000007;

void P(int x) {cout << x << endl;}
void P(long x) {cout << x << endl;}
void P(double x) {cout << x << endl;}
void P(ll x) {cout << x << endl;}
void P(string x) {cout << x << endl;}
void P(char x) {cout << x << endl;}

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  int n, m;
  cin >> n >> m;
  string a[n], b[m];
  rep (i, n) {
    cin >> a[i];
  }
  rep (i, m) {
    cin >> b[i];
  }


  rep (i, n - m + 1) {
    rep (j, n - m + 1) {
      // cout << i << ", " << j << endl;
      int flag = 1;
      rep (k, m) {
        rep (l, m) {
          if (a[i + k][j + l] != b[k][l]) {
            flag = 0;
            break;
          }
        }
        if (flag == 0) break;
      }
      if (flag == 0) continue;
      Yes;
      return 0;
    }
  }
  No;

  return 0;
}
