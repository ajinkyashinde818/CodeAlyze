#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

long long MOD = 1000000007;

int main(){
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int ans=0;
    for(int i=0; i<=N/R; i++){
        for(int j=0; j<=(N-i*R)/G; j++){
            if((N-i*R-j*G)%B==0){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
