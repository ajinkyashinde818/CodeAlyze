#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

int main(void)
{
    long long R, G, B, N, i, j, sum=0, ans=0;

    cin >> R >> G >> B >> N;

    for(i=0; i<=N/R; i++){
        sum = R*i;

        for(j=0; j<=(N-sum)/G; j++){
            sum += G*j;
            
            if((N-sum)%B==0){
                ans++;
            }

            sum = R*i;
        }
    }

    cout << ans << endl;

    return 0;
}
