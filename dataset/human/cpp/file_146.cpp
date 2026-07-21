#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {

    int N, R, G, B;

    cin >> R >> G >> B >> N;


    int cou, iN;

    for (int ri = 0; ri <= N; ri++)
    {
        for(int gi = 0; gi <= N; gi++)
        {
            iN = N - R * ri - G * gi;
            if(iN % B == 0 && iN >= 0)
            {
                cou++;
            }
        }
    }
    
    cout << cou << endl;

    return 0;
}
