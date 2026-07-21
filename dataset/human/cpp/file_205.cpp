#include <iostream>

using namespace std;

int main(){
    int r, g, b, n; cin >> r >> g >> b >> n;
    int ans=0;
    for(int ri=0; ri<=n; ++ri){
        for(int gi=0; gi<=n; ++gi){
            if(n-(ri*r+gi*g)>=0 && (n-(ri*r+gi*g))%b==0) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
