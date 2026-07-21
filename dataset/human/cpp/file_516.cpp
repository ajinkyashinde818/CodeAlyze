#include <bits/stdc++.h>
using namespace std;

int main(void)
{

   int r, g, b, n;
   cin >> r >> g >> b >> n;

   int cnt = 0;

   int R = (n + r - 1) / r;
   int G = (n + g - 1) / g;
   int B = (n + b - 1) / b;



   for (int i = 0; i <= R; i++)
   {
      for (int j = 0; j <= G; j++)
      {
         int sum = (n - i * r - j * g);
         if (sum % b == 0 && (sum / b) >= 0)
         {
            cnt++;
         }
      }
   }
   cout << cnt << endl;
   return 0;
}
