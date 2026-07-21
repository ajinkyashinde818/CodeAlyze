#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <stack>
#include <set>
#include <bitset>
#include <deque>
#pragma GCC optimize(3 , "Ofast" , "inline")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std ;
#define ios ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)
#define x first
#define y second
#define pb push_back
#define ls rt << 1
#define rs rt << 1 | 1
typedef long long ll ;
const double esp = 1e-6 , pi = acos(-1) ;
typedef pair<int , int> PII ;
const int N = 1e6 + 10 , INF = 0x3f3f3f3f , mod = 1e9 + 7;
int a[N] , b[N] , ca[N] , cb[N] ;
int work()
{
  int n ;
  cin >> n ;
  for(int i = 0; i < n ;i ++ ) cin >> a[i] , ca[a[i]] ++ ;
  for(int i = 0; i < n ;i ++ ) cin >> b[i] , cb[b[i]] ++ ;
  for(int i = 1; i <= n ;i ++ )
   if(ca[i] + cb[i] > n)
    return 9 * puts("No") ;
  for(int i = 1; i <= n ;i ++ )
   ca[i + 1] += ca[i] , cb[i + 1] += cb[i] ;
   int s = 0 ;
   puts("Yes") ;
   for(int i = 1; i <= n ;i ++ ) s = max(s , cb[i] - ca[i - 1]) ;
  for(int i = 0 ;i < n ;i ++ )
   cout << b[(i + s) % n] << " " ;
  puts("") ;
  return 0 ;
}
int main()
{
  //   freopen("C://Users//spnooyseed//Desktop//in.txt" , "r" , stdin) ;
  //   freopen("C://Users//spnooyseed//Desktop//out.txt" , "w" , stdout) ;

  work() ;
  return 0 ;
}
/*
*/
