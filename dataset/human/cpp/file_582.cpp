#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <bitset>
#include <list>
#include <map>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans=0;
    for(int i=0; i*r<=n; i++){
        for(int j=0; j*g<=n; j++){
            int a=n-i*r-j*g;
            if(a>=0 && a%b==0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
