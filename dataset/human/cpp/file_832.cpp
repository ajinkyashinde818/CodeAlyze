#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <climits>

using namespace std;

int main(void)
{

    int r,g,b,n;
    cin >>r >>g >>b >>n;

    int ct = 0;
    for(int ri = 0; ri * r <= n; ri++){
        for(int gi = 0; ri * r + gi * g <= n; gi++){
            int diff =  n - (ri * r + gi*g);
            if(diff % b == 0){
                ct++;
            }
        }
    }
    printf("%d\n", ct);

    return 0;
}
