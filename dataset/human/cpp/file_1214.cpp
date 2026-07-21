#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <cfloat>
#include <math.h>


#define fs first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> P;


int main(){
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int res = 0;
    for(int i = 0; i <= N; i += R){
        for(int j = 0; i + j <= N; j += G){
            if((N - (i + j)) % B == 0){
                res++;
            }
        }
    }
    cout << res << endl;


    return 0;
}
