#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <map>
#include <string>
#include <math.h>
using namespace std;


int main() {

    int i=0;
    int N,R;
    cin >> N >> R;
    if(N<10){
    int ans = R+100*(10-N);
    cout << ans << endl;
    }else{
        cout << R << endl;
    }
    
    return 0;
}
