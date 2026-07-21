#include<bits/stdc++.h>
using namespace std;

pair<int64_t, int> ar[1234 * 1234];
int64_t bests[1234 * 1234];
int64_t cbests[1234 * 1234];

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   for (;;)
   {
      int n;
      int64_t c;
#ifdef _DEBUG
      const auto read =
#endif
         scanf("%d%" PRId64 "", &n, &c);
#ifdef _DEBUG
      if (read != 2)
         break;
#endif
      for (auto i = 0; i < n; i++)
         scanf("%" PRId64 "%d", &ar[i].first, &ar[i].second);

      int64_t m = 0;
      {
         //clockwise
         int64_t tv = 0, bv = 0;
         for (auto i = 0; i < n; i++)
         {
            tv += ar[i].second;
            bv = max(bv, tv - ar[i].first);
            bests[i] = bv;
         }
         m = max(m, bv);
      }
      {
         //counterclockwise
         int64_t tv = 0, bv = 0;
         for (auto i = n - 1; 0 <= i; --i)
         {
            tv += ar[i].second;
            const auto wd = c - ar[i].first;
            bv = max(bv, tv - wd);
            cbests[i] = bv;
         }
         m = max(m, bv);
      }
      //if (1 < n)
      {
         {
            //clockwise then counterclockwise
            int64_t bv = 0;
            for (auto i = 0; i < n - 1; i++)
            {
               const auto& wd = ar[i].first;
               const auto tv = bests[i] + cbests[i + 1] - wd;
               bv = max(bv, tv);
            }
            m = max(m, bv);
         }
         {
            //counterclockwise then clockwise
            int64_t bv = 0;
            for (auto i = n - 1; 0 < i; --i)
            {
               const auto wd = c - ar[i].first;
               const auto tv = cbests[i] + bests[i - 1] - wd;
               bv = max(bv, tv);
            }
            m = max(m, bv);
         }
      }
      cout << m << '\n';
#ifdef _DEBUG
      memset(bests, 0, sizeof bests);
      memset(cbests, 0, sizeof cbests);
#else
      break;
#endif
   }

   return 0;
}
