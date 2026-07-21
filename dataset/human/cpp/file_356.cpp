#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <set>
#include <map>
using namespace std;

const double PI=acos(-1);

int main(){
    long a, b, c, n, cnt = 0;
    cin >> a >> b >> c >> n;
    for(int aa = 0; a*aa <= n; aa++){
        for(int bb = 0; b*bb <= n; bb++){
            if(a*aa + b*bb <= n && (n - (aa*a + b*bb))%c == 0) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
