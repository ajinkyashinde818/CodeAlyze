#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <numeric>
#include <iomanip>
#include <limits>

using namespace std;

int main(){

    int ans=0;

    int n,r;

    cin>>n>>r;

    if(n>=10){
        ans=r;
    }
    else{
        ans=r+100*(10-n);
    }

    cout<<ans<<endl;

    return 0;
}
