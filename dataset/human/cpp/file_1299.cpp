#include <iostream>
using namespace std;


int main()
{
    int R, G, B, N;
    cin >> R >> G >> B >> N;


    int ans = 0;
    for( int i = 0; i <= N/R; ++i ){
        for( int j = 0; j <= N/G; ++j ){
            int numBalls = R*i + G*j;
            if( numBalls <= N and (N-numBalls)%B == 0 ) ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}
