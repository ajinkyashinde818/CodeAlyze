#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <limits>
#include <iomanip>
using namespace std;

int main(){

    int N, R;
    cin >> N >> R;

    int ans = 0;

    if( N < 10 ){
        ans = R + 100 * (10 - N);
    }else{
        ans = R;
    }

    cout << ans << endl;

}
