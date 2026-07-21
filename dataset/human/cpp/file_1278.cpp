#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{   
    int r,g,b,n;cin>>r>>g>>b>>n;
    int cnt=0;
    for (int i=0;i<=n/r;++i){
        for(int j=0;j<=n/g;++j){
            int temp = n-r*i-g*j;
            // cout << temp << endl;
            if(temp%b==0 && temp/b>=0)cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
