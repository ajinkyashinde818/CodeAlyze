#include <iostream>
#include <stdlib.h>
#include <vector> //vector
#include <algorithm> //sort()

using namespace std;

long a, b, c, d, i, j, k, n, R, G, B;


int main(){
//////////////////////////////////////////////////////


    // cout << "Hello, World!" << endl;

    cin >> R >> G >> B >> n;
    long ball = 0;
    //赤個数

    long ok = 0;
    
    for ( int rn = 0 ; rn <= n / R ; rn ++ )
    {
        ball = rn * R;
        long nokoriball = n - ball;
        for ( int gn = 0 ; gn <= nokoriball / G ; gn++ )
        {
            ball = rn * R + gn * G;
            
            // 割り切れない場合
            if ( (n - ball) % B != 0 )
            {
                //cout << rn << "+" << gn << "+" << 0 << "," <<rn*R + gn*G << " < " << n << endl;

                continue;
            }
            else
            {
                long bn;
                bn = (n - ball) / B;
                ok ++;
                //cout << rn << "+" << gn << "+" << bn << "," <<rn*R + bn*B + gn*G << " = " << n << endl;
            }
        }
    }

    // cout << "n:" << n << endl;

    // vector<long> input(n);
    // for (int i = 0 ; i < n ; i ++ )
    // {
    //     cin >> input[i];
        // cout << "input[" << i << "]=" << input[i] << endl;
    // }

    // sort(input.begin() , input.end());

    // uint64_t max = numeric_limits<uint64_t>::max();



    // long sum = 0;
    // for ( int i = 0 ; i < n ; i ++ )
    // {
    //     sum += i;
    // }






    cout <<   ok   << endl;

//////////////////////////////////////////////////////
// Ctrl + Opt + N to make
    return 0;
}
