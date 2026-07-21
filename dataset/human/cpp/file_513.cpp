#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int ans = 0;
    for(int i = 0; i <= N/R; i++){
        for(int j = 0; j <= N/G; j++){
            if(N - i*R - j*G >= 0){
                if((N - i*R - j*G) % B == 0)
                    ans++;
            }
        }
    }
    cout << ans <<endl;
}
