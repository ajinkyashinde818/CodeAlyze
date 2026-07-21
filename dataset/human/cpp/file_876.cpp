#include "bits/stdc++.h"
#include <algorithm>

using namespace std;


int main(){
    int n,r,g,b;
    cin>>r>>g>>b>>n;


    int ans=0;

    vector <int> num(3);
    num[0] = r;
    num[1] = g;
    num[2] = b;
    sort(num.begin(),num.end());
    for (int i = 0; i*num[0] <=n ; i++)
    {
        for (int j = 0; i*num[0]+j*num[1] <= n; j++)
        {
            if((n-i*num[0]-j*num[1])%num[2]==0){
                ans++;
            }
        }
        
    }
    
    
    cout << ans <<endl;
    return(0);
}
