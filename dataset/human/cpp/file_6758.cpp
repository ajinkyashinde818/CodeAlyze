#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define pii pair <int, int>
#define XX first
#define YY second

// constants:
const int mn = 200005;
const int mod = 1000000007;
const long long inf = 4444444444444444444;
const int sminf = 1111111111;
const bool is_multitest = 0;
const bool is_interactive = 0;

// i/o methods:
const bool input_from_file = 0;
const bool output_to_file = 0;
#define filename ""
#define in_extension "inp"
#define out_extension "out"

// data preprocessing: (e.g.: divisor generating, prime sieve)
void preprocess()
{
  
}

// global variables:
int n;
int A[mn], B[mn];
int cntA[mn], cntB[mn];
bool sort1(int a, int b) {
  if (cntA[a] + cntB[a] == cntA[b] + cntB[b]) return a<b;
  return cntA[a] + cntB[a] < cntA[b] + cntB[b];
}
// main solution goes here:
void execute(int test_number)
{
  cin>>n;
  // int u;
  for (int i=1; i<=n; i++) {
    cin>>A[i];
    cntA[A[i]]++;
  }
  for (int i=1; i<=n; i++) {
    cin>>B[i];
    cntB[B[i]]++;
  }

  for (int i=1; i<=n; i++) if (cntA[i] + cntB[i] > n) {
    cout<<"No\n";
    return;
  }

  cout<<"Yes\n";
  sort(A+1, A+n+1, sort1);
  sort(B+1, B+n+1, sort1);
  int ptrA = n, ptrB = n;
  vector <pii> ans;
  while (ans.size() < n) {
    if (sort1(A[ptrA], B[ptrB])) {
      int u = B[ptrB];
      while (ans.size() < n) {
        if (B[ptrB] != u) break;
        ans.push_back({0, u});
        ptrB--;
      }
    } else {
      int u = A[ptrA];
      while (ans.size() < n) {
        if (A[ptrA] != u) break;
        ans.push_back({u, 0});
        ptrA--;
      }
    }
  }

  for (int i=0; i<n; i++) {
    if (ans[i].XX == 0) {
      ans[i].XX = A[ptrA];
      ptrA--;
    } else {
      ans[i].YY = B[ptrB];
      ptrB--;
    }
  }

  sort(ans.begin(), ans.end());
  for (int i=0; i<n; i++) cout<<ans[i].YY<<" ";
}
// REMEMBER TO CHOOSE TEST METHODS
// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Solution by low_



















signed main()
{
#ifdef lowie
    if (!is_interactive)
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
#else
    if (input_from_file) freopen(filename"."in_extension, "r", stdin);
    if (output_to_file) freopen(filename"."out_extension, "w", stdout);
#endif
    if (!is_interactive)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    preprocess();
    int ntest;
    if (is_multitest) cin >> ntest;
    else ntest = 1;

    for (int testno = 1; testno <= ntest; testno++)
    // use for instead of while to serve facebook hacker cup test format
    {
        execute(testno); // only start coding in this function, not in main
    }
}
// Template by low_
// Contact me via mail: ttuandung1803@gmail.com
// ...or codeforces: https://www.codeforces.com/profile/low_
// ...or linkedIn: https://www.linkedin.com/in/daniel-to-83045a19a/
// I use VS Code. Here's a JSON format for my template: https://pastebin.com/xH2yRdwx
