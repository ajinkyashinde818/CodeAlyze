#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int r_,g_,b_,n;

    cin >> r_ >> g_ >> b_ >> n;


    int a = 0;
    int b = 0;
    int c = 1;

    int ans = 0;

    for(;g_*b<=n;b++){
        for(;r_*a<=n;a++){
            
            c=((n-(r_*a)-(g_*b))/b_);
            
            //cout <<a<<b<<c<<endl;
            
            if(((n-(r_*a)-(g_*b))%b_)==0&&r_*a + g_*b + b_*c==n&&c>=0){
                ans++;
            }
        }
        a=0;
    }

    cout << ans;

    //n = r_*a + g_*b + b_*c 
    //c = ((n-(r_*a)-(g_*b))/b_)


    return 0;
}
