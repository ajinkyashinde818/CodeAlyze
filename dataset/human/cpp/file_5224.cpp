#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;


int main(){
    int N, R; cin >> N >> R;
    if(N < 10){
        R += 100*(10-N);
    }
    cout << R << endl;
}
