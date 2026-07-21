#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int N, R;
    cin >> N >> R;
    if(N >= 10){
        cout << R << endl;
    }else{
        cout << R+100*(10-N) << endl;
    }
}
