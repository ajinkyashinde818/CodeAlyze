#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<cctype>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll R,G,B,N;
    cin >> R >> G >> B >> N;
    ll r,g,b,ans=0;
    for(r=0;r<=N/R;r++){
        for(g=0;g<=N/G;g++){
            b=(N-R*r-G*g)/B;
            if(r*R+g*G+b*B==N&&b>=0)ans++;
        }
    }
    cout << ans;
    return 0;
}
