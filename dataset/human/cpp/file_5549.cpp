#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <iomanip>
#include <map>

using namespace std;



int main(){

    int n, r;
    cin >> n >> r;

    int ans = 0;
    if(n<10){
        ans = 100*(10-n) + r;
    } else{
        ans = r;
    }

    cout << ans << endl;




    return 0;
}
