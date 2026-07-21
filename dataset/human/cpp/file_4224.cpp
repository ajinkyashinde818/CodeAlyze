#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main()
{
        ll T;
        ll mul = 1;
        ll cnt = 0;

        cin >> T;
        

        while ( T != 0 ) {
                T -= mul, cnt++;
                if ( mul == 1 && T / mul >= 3 || T / mul >= 4 ) {
                        if ( mul == 1 || (T / mul) % 3 != 0 ) mul *= 3;
                } else break;
        }
        
        //cout << mul << " " << cnt << " " << T << endl;

        while ( mul > 3 ) {
                ll value = T / (mul / 3);
                ll plus = (value - 1) / 3;

                cnt += plus;
                T -= plus * mul;
                //cout << " " << mul << " " << cnt << " " << T << endl;
                mul /= 3;
        }
        
        if ( mul == 3 ) {
                cout << cnt + T / 3 + T % 3 << endl;
        } else {
                cout << cnt + T << endl;
        }

        return ( 0 );
}
