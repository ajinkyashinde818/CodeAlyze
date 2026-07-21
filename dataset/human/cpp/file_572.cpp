#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
typedef long long ll;

int main(){
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    for (int i = 0; i <= n; i+=r)
    {
        for (int j = 0; j <= n-i; j+=g)
        {
            if((n-i-j)%b==0){
                ans++;
            }
        }
        
    }
    cout << ans<< endl;
    
}
