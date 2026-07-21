#include <iostream>
//#include <string>
#include <algorithm>
#include <cmath>
//#include <vector>
//#include <limits>

using namespace std;
/*void amin(long long  &x,long long  y)
{
    if ( y < x ) {
        x   =   y;
    }
}*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N;//,a;
    long long sum[200001];
    sum[0] = 0;
    long long min_num = 2 * 10000000000;//pow(10, 9.0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        //cin >> a;
        cin >> sum[i];
        sum[i] += sum[i - 1];// + a;
    }
    
    for ( int i = 1; i < N; i++) {
        min_num = min(min_num, abs(sum[N] - (2 * sum[i])));
        //amin(min_num, abs(sum[N] - (2 * sum[i])));
    }
    cout << min_num << '\n';

}
