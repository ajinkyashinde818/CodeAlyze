#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int r,g,b,n;
    cin >> r >> g >> b >> n;

    long pattern = 0;
    for(int ri = 0 ; ri <= (n / r) ; ri++){
        for(int gi = 0; gi <= (n / g) ; gi++){
            int left = n - ri * r -gi * g;
            if(left < 0){
                continue;
            }
            if(left % b == 0){
                pattern++;
            }
        }
    }

    cout << pattern << endl;

    return 0;
}
