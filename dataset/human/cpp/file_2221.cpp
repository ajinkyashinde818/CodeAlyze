#include <bits/stdc++.h>

using namespace std;


int main()
{
   long N, tmp, sum = 0;
   vector<long> vec;
    long m1 = LONG_MAX;
    long c=0;

   cin >> N;
   for (int i = 0; i < N; i++) {
       cin >> tmp;
       if (m1 > abs(tmp)) {
           m1 = abs(tmp);
       }
       sum += abs(tmp);
       if (tmp < 0)
            c++;
   }

    if (c%2 == 0) {
        cout << sum << endl;
    } else {
        cout << sum - m1*2 << endl;
    }
    
    return 0;   
};
