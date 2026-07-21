#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

int main(){
    int N,R,T;
    cin >> N >> R;
    T = R;
    if(N <= 9){
        R = T + (100 * (10 - N));
        cout << R << endl;
    }else cout << R << endl;
    return 0;
}
