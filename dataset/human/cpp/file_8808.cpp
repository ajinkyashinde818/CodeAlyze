#include <iostream>
#include <vector>
#include <string>
//#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main() {
    LL n;
    LL m;
    cin >> n >> m;

    vector<string> a(n);
    vector<string> b(m);
    for(LL i=0; i<n; i++){
        cin >> a[i];
    }
    for(LL i=0; i<m; i++){
        cin >> b[i];
    }

    bool ans=false;
    bool is_ok;
    for(LL i=0; i+m<=n; i++){
        for(LL j=0; j+m<=n; j++){
            is_ok=true;
            for(LL k=0; k<m; k++){
                for(LL l=0; l<m; l++){
                    if(a[i+k][j+l]!=b[k][l]){
                        is_ok=false;
                    }
                }
            }
            if(is_ok==true){
                ans=true;
            }
        }
    }

    if(ans==true){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
