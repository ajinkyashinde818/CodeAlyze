#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <regex>
#include <map>
#include <set>
using namespace std;
int main(){
    int R,G,B,N;
    cin >> R >> G >> B >>N;
    int r=0,g=0,b=0,ans=0;
    for(r=0;r<=N;r++){
        for(g=0;g<=N;g++){
                int tmp = (R*r)+(G*g);
                if(tmp <= N && (N-tmp)%B==0){
                    ans++;
                }
            }
        }
    
    cout << ans << endl;
    return 0;
}
