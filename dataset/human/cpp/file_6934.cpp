#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PII;

// chmax, chmin
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}

template <typename T>
function<T(T, T)> op_max = [](T a, T b) -> T { return max(a, b); };
template <typename T>
function<T(T, T)> op_min = [](T a, T b) -> T { return min(a, b); };

template <typename T>
function<T(T, T)> op_sum = [](T a, T b) -> T { return a + b; };

using namespace std;
//********************  dumps ************************//

template <typename T>
void dump(const T &data, vector<int> &iter)
{
  cout << data << " ";
}
template <typename T>
void dump(const vector<T> &data, vector<int> &iter)
{
  for (auto elem : data)
    dump(elem, iter);
  cout << endl;
}

template <typename T>
void dump(const vector<vector<T>> &data, vector<int> &iter)
{
  for (auto elem : iter)
  {
    cout << "[" << elem << "]";
  }
  cout << endl;
  for (int i = 0; i < data.size(); i++)
  {
    iter.push_back(i);
    dump(data[i], iter);
    iter.pop_back();
  }
  cout << endl;
}

template <typename T>
void dump(const vector<T> &data, int dummy)
{
  for (int i = 0; i < data.size(); i++)
  {
    cout << "[" << i << "] " << data[i] << endl;
  }
}
template <typename T>
void dump(const T &data)
{ // T : data, U = base type val.
  vector<int> iter;
  dump(data, iter);
}
///////////////////////////////////////////////

const string YES = "Yes";
const string NO = "No";
vector<LL> ans;

bool solve(long long N, std::vector<long long> A, std::vector<long long> B)
{
  ans.resize(N + 10);

  vector<vector<int>> originA(N + 10), originB(N + 10);

  priority_queue<PII> Ainfo;
  priority_queue<PII> Binfo;
  map<LL, LL> Amap, Bmap;
  for (int i = 0; i < N; i++)
  {
    int a = A[i];
    Amap[a]++;
    originA[a].push_back(i);
  }
  for (int i = 0; i < N; i++)
  {
    int b = B[i];
    Bmap[b]++;
    originB[b].push_back(i);
  }
  for (auto aval : Amap)
  {
    Ainfo.push(PII(aval.second, aval.first));
  }
  for (auto bval : Bmap)
  {
    Binfo.push(PII(Amap[bval.first] + bval.second, bval.first));
  }
  while (!Ainfo.empty())
  {
    PII remain = Ainfo.top();
    Ainfo.pop();

    while (remain.first > 0)
    {
      auto func = [&]() {
        while (true)
        {
          PII tmp = Binfo.top();
          Binfo.pop();
          LL val = Amap[tmp.second] + Bmap[tmp.second];
          if (val != tmp.first)
          {
            Binfo.push(PII(val, tmp.second));
          }
          else
            return tmp;
        }
      };
      PII cand = func();
      PII hozon = PII(-1, -1);
      if (cand.second == remain.second)
      {
        hozon = cand;
        if (Binfo.empty())
          return false;
        cand = func();
      }
      LL numB = Bmap[cand.second];
      LL numA = Amap[remain.second];
      for (int i = 0; i < 1; i++)
      {

        int posA = originA[remain.second].back();
        int posB = originB[cand.second].back();
        originA[remain.second].pop_back();
        originB[cand.second].pop_back();
        ans[posA] = posB;
        Amap[remain.second]--;
        Bmap[cand.second]--;
      }

      //if (remain.first > numB)
      if (remain.first > 1)
      {
        PII tmp = PII(remain.first - 1 /*numB*/, remain.second);
        Ainfo.push(tmp);
        remain = PII(-1, -1);
        // remain = tmp;
      }

      if (1 < numB)
      {
        PII tmp = PII(Amap[cand.second] + Bmap[cand.second], cand.second);
        Binfo.push(tmp);
        remain = PII(-1, -1);
      }
      else
      {
        remain = PII(-1, -1);
      }
      if (hozon != PII(-1, -1))
      {
        hozon = PII(Amap[hozon.second] + Bmap[hozon.second], hozon.second);
        Binfo.push(hozon);
      }
    }
  }
  return true;
}

int main()
{
  cout << setprecision(10);
  long long N;
  scanf("%lld", &N);
  std::vector<long long> A(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &A[i]);
  }
  std::vector<long long> B(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &B[i]);
  }
  vector<LL> BB = B;
  bool res = solve(N, std::move(A), std::move(B));
  cout << (res ? YES : NO) << endl;
  if (res)
  {
    vector<int> cnt(N + 10, 0);
    for (int i = 0; i < N; i++)
      cnt[ans[i]]++;
    for (int i = 0; i < N; i++)
      if (cnt[i] > 1)
        cout << "false" << endl;
    for (int i = 0; i < N; i++)
    {
      cout << BB[ans[i]];
      if (i == N - 1)
        cout << endl;
      else
        cout << " ";
    }
  }
  return 0;
}
