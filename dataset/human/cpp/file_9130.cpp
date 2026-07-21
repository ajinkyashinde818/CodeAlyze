#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
int main(void)
{
   int n, m;
   char a[55][55];
   char b[55][55];

   cin >> n >> m;

   if (n < m) {
       cout << "No" << endl;
       return 0;
   }

   for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
           cin >> a[i][j];
       }
   }

   for (int i = 0; i < m; i++) {
       for (int j = 0; j < m; j++) {
           cin >> b[i][j];
       }
   }

   for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
           if (i+m-1 >= n || j+m-1 >= n) {
               continue;
           }
           bool flag = true;
           for (int k = 0; k < m; k++) {
               for (int l = 0; l < m; l++) {
                   if (a[k+i][l+j] != b[k][l]) {
                       flag = false;
                   }
               }
           }
           if (flag) {
               cout << "Yes" << endl;
               return 0;
           }
       }
   }

   cout << "No" << endl;

   return 0;
}
