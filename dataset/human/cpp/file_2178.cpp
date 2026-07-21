#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

int main (){

    int n;
    cin >> n;

    long a[n];
    long sum = 0;

    int count = 0;
    int zerocount = 0;
    long long ans;
    long long min = 100000000;

    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += abs(a[i]);

        if (abs(a[i])< min) {
            min = abs(a[i]);
        }

        if (a[i] < 0){

            count ++;

        }else if (a[i] == 0 ){
  
            zerocount ++;
        }
    }

    if (count % 2 == 0 || zerocount > 0){

        ans = sum;

    } else{

        ans = sum - 2 * min;

    }
    
    cout << ans << endl;

    return 0;

    
}
