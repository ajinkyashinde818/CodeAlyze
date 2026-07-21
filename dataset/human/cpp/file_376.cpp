#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<limits>
#include<iomanip>
#include<cmath>
#include<climits>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int mod=1e9+7;

int gcd(int a,int b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}
int main(){
    int r,g,b,n;
    cin >> r >> g>> b >> n;
    int ans=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i*r+j*g>n){
                break;
            }
            if((n-i*r-j*g)%b==0)    ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
