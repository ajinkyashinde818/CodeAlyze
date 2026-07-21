#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>
#include <numeric>
#include <queue>
#include <sstream>
#include <set>
using namespace std;

int64_t min(int64_t a,int64_t b) {
    if (a > b)
    {
        return b ;
    }else
    {
        return a ;
    }
}


int main(){
    int n ;
    cin >> n ;
    vector<int64_t> a(n) ;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a.at(i) ;
    }
    vector<int64_t> s(n) ;
    s.at(0) = a.at(0) ;
    for (size_t i = 1; i < n; i++)
    {
        s.at(i) = s.at(i-1) + a.at(i) ;
    }
    int64_t ans = INT64_MAX;
    for (size_t i = 0; i < n-1; i++)
    {
        ans = min(ans,abs(2*s.at(i) -s.at(n-1) )) ;
    }
    cout << ans << endl ;
    
}
