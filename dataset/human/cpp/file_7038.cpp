#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <array>
#include <bitset>

long long mod = 1e9 + 7;
class Mint
{
public:
  long long x;
  Mint(){}; // 引数なしでも定義できるように引数なしコンストラクタも用意しておく
  Mint(long long a)
  {
    x = a % mod;
    while (x < 0)
    {
      x += mod;
    }
  };
  Mint &operator+=(const Mint &a)
  {
    x += a.x;
    x %= mod;
    return *this;
  }
  Mint &operator-=(const Mint &a)
  {
    x += (mod - a.x);
    x %= mod;
    return *this;
  }
  Mint &operator*=(const Mint &a)
  {
    x *= a.x;
    x %= mod;
    return *this;
  }

  // a^n mod を計算する
  // Useaeg: Mint z = Mint(2).pow(n);
  Mint pow(long long n) const
  {
    if (n == 0)
      return Mint(1);
    Mint y = pow(n >> 1); // pow(n/2)を計算する
    y *= y;
    if (n % 2 == 1)
      y *= *this;
    return y;
  }

  // a^{-1} mod を計算する
  Mint modinv(const Mint &a) const
  {
    return a.pow(mod - 2);
  }

  Mint &operator/=(const Mint &a)
  {
    x *= modinv(a).x;
    x %= mod;
    return *this;
  }

  Mint operator+(Mint &a) const
  {
    Mint y(*this);
    y += a;
    return y;
  }

  Mint operator-(Mint &a) const
  {
    Mint y(*this);
    y -= a;
    return y;
  }

  Mint operator*(Mint &a) const
  {
    Mint y(*this);
    y *= a;
    return y;
  }

  Mint operator/(Mint &a) const
  {
    Mint y(*this);
    y /= a;
    return y.x;
  }
};
  // nCk @mod を計算する
Mint nCk(Mint &n, const long long k)
{
  Mint y = Mint(1);
  Mint iy = Mint(1);
  Mint one = Mint(1);
  // 割り算の演算は時間がかかるので最後に1度だけ行うようにすること
  for (Mint i(0); (i.x) < k; i.x++)
  {
    y *= (n - i);
    iy *= (i + one);
  }
  return y / iy;
}

// nPk @mod を計算する
Mint nPk(Mint &n, long long k)
{
  Mint y(1);
  for (Mint i(0); (i.x) < k; i.x++)
  {
    y *= (n - i);
  }
  return y;
}

class UnionFind
{
private:
  int n;
  std::vector<int> parent;

public:
  UnionFind(int num) : n(num)
  {
    parent = std::vector<int>(n);
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
    }
  }
  int GetRoot(int i)
  {
    int n = i;
    while (parent[n] != n)
    {
      n = parent[n];
    }
    parent[i] = n;
    return n;
  }

  bool SameGroup(int n, int m)
  {
    n = this->GetRoot(n);
    m = this->GetRoot(m);
    return n == m;
  }

  bool Unite(int n, int m)
  {
    n = this->GetRoot(n);
    m = this->GetRoot(m);
    if (n == m)
      return false;
    parent[n] = m;
    return true;
  }
};

int getgcd(int a, int b)
{
  int max = std::max(a, b);
  int min = std::min(a, b);
  if (min == 0)
    return max;
  return getgcd(min, max % min);
}

//Mint nCk_pascar[1004][1004];
// nの値までのnCkをパスカルの三角形から求めておく
/*void Calc_nCk_pascar(int n){
  for (int i=0; i<=n; i++) {
    for (int j=0; j<=i; j++) {
      if (j==0 || j==i) nCk_pascar[i][j] = Mint(1);
      else nCk_pascar[i][j] = nCk_pascar[i-1][j-1] + nCk_pascar[i-1][j];
    }
  }
  return;
}*/

long long nCk_pascar[1004][1004];
// nの値までのnCkをパスカルの三角形から求めておく
void Calc_nCk_pascar(int n){
  for (int i=0; i<=n; i++) {
    for (int j=0; j<=i; j++) {
      if (j==0 || j==i) nCk_pascar[i][j] = 1;
      else nCk_pascar[i][j] = nCk_pascar[i-1][j-1] + nCk_pascar[i-1][j];
    }
  }
  return;
}

Mint mynCk(int n, int k)
{
  if (2 * k > n)
    return mynCk(n, n - k);
  Mint retval(1);
  Mint iretval(1);
  for (int i = 0; i < k; i++)
  {
    retval *= Mint(n - i);
  }
  for (int i = 1; i <= k; i++)
  {
    iretval *= Mint(i);
  }
  return retval / iretval;
}


int main()
{
  int N;
  std::cin >> N;
  std::vector<int > A(N), B(N);
  std::vector<int > num(2*N+4, 0);
  std::vector<int > Apos[N+4], Bpos[N+4];
  std::set<int > Anum, Bnum; 
  for (int i=0; i<N; i++) {
    std::cin >> A[i];
    //A[i] = i%2+1;
    Apos[A[i]].push_back(i);
    num[A[i]]++;
    Anum.insert(A[i]);
  }
  for (int i=0; i<N; i++) {
    std::cin >> B[i];
    //B[i] = i%2+1;
    Bpos[B[i]].push_back(i);
    num[B[i]]++;
    Bnum.insert(B[i]);
  }

  std::set<int > cnt[2*N+4];
  // printf("cnt[6].size()=%d\n", cnt[6].size());
  int maxnum = -1;
  for (int i=1; i<=N; i++) {
    if (num[i]!=0) {
      cnt[num[i]].insert(i);
      // printf("insert %d into cnt[%d]\n", i, num[i]);
    }
    maxnum = std::max(maxnum, num[i]);
  }
  // printf("cnt[6].size()=%d\n", cnt[6].size());
  if (maxnum>N) {
    printf("No\n");
    return 0;
  }
  
  // printf("L309\n");
  auto getany = [&](std::set<int> *S, int v) {
    int ret = -1;
    // printf("S size = %d\n", S->size());
    auto itr = S->begin();
    while(itr!=S->end()){
      if (*itr!=v) {
        ret = *itr;
        break;
      }
      itr++;
    }
    return ret;
    //printf("Error\n");
  };
  std::vector<int > ans(N);
  for (int i=N; i>0; i--) {
    // printf("i=%d\n", i);
    // printf("Apos[3],size()=%d, Apos[1]=%d\n", Apos[3].size(), Apos[1].size());
    int target_num = cnt[i].size();
    int x, y;
    
    // printf("target_num=cnt[%d].size()=%d\n", i,target_num);
    // Aからx、Bからyを選択する
    if (target_num==0) {
      x = *Anum.begin();
      //y=0;//x=0;
      y = getany(&Bnum, x);
    } else if (target_num == 1) {
      x = *cnt[i].begin();
      // printf("L338: Apos[%d],size()=%d\n", x, Apos[x].size());
      if (Apos[x].size()>0) {
        y = getany(&Bnum, x);
      } else {
        y = getany(&Anum, x);
        std::swap(x, y);
      }
    } else {
      if (target_num>2) return 0;
      x = *cnt[i].begin();
      y = *(++cnt[i].begin());
      // printf("now x=%d, y=%d\n", x, y);
      if (Apos[x].size()==0) {
        std::swap(x, y);
      }
    }
    
    // printf("x=%d, y=%d\n", x, y);
    ans[Apos[x][Apos[x].size()-1]] = y;
    if (Apos[x].size()==0) return 0;
    Apos[x].pop_back();
    // printf("num[x] = %d\n", num[x]);
    // printf("cnt[6].size()=%lu\n", cnt[6].size());
    // printf("cnt[num[x]].size()=%lu",cnt[num[x]].size());
    
    if (num[x]==0) return 0;
    if (cnt[num[x]].find(x) == cnt[num[x]].end()) {printf("NG"); return 0;};
    cnt[num[x]].erase(cnt[num[x]].find(x));
    num[x]--;
    cnt[num[x]].insert(x);
    // printf("cnt[%d].push(%d)\n",num[x],x);

    if (Apos[x].size()==0) {
      auto itr = Anum.find(x);
      Anum.erase(itr);
    }
    if (Bpos[y].size()==0) return 0;
    Bpos[y].pop_back();
    // printf("num[y] = %d\n", num[y]);
    if (num[y]==0) return 0;
    if (cnt[num[y]].find(y) == cnt[num[y]].end()) {printf("NG"); return 0;};
    cnt[num[y]].erase(cnt[num[y]].find(y));
    num[y]--;
    cnt[num[y]].insert(y);
    // printf("cnt[%d].push(%d)\n",num[y],y);
    if (Bpos[y].size()==0) {
      auto itr = Bnum.find(y);
      Bnum.erase(itr);
    }
  }
  printf("Yes\n");
  for (int i=0; i<N; i++) {
    printf("%d%c",ans[i],(i==N-1)?'\n':' ');
    // printf("i=%d\n", i);
  }
  // printf("end\n");
  
  return 0;
}
