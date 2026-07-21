#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <sstream>
#include <numeric>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int64_t> a(n,0) ;
    vector<int64_t> plus(0) ;
    vector<int64_t> minus(0);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a.at(i) ;
        if (a.at(i) < 0)
        {
            minus.push_back(a.at(i));
            a.at(i) *= -1 ;
        }else
        {
            plus.push_back(a.at(i)) ;
        }
        
    }
    int64_t ans = accumulate(a.begin(),a.end(),int64_t(0)) ;
    /*for (size_t i = 0; i < n; i++)
    {
        ans += a.at(i) ;
    }
    */
    
    if (minus.size() % 2 == 1)
    {
        sort(a.begin(),a.end()) ;
        ans -= 2*a.at(0) ;
    }
    cout << ans << endl ;
}
