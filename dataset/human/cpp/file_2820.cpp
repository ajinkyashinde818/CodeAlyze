typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}


int main() {
    ll n;
    ll a[100010];
    ll sum = 0;
    ll count =0;
    ll min_minus =-1000000010;
    ll min_plus = 1000000010;
    bool has_0 = false;
    
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum += (ll)abs(a[i]);
        
        if(a[i]<0){
            count++;
            min_minus = max(min_minus,a[i]);
        }else if(a[i]>0){
            min_plus = min(min_plus,a[i]);
        }else{
            has_0 = true;
        }
    }
    
    if(has_0){
        std::cout << sum << std::endl;
        return 0;
    }
    
    if(count%2==0){
        std::cout << sum << std::endl;
        return 0;
    }else{
        std::cout << sum - (ll)abs(min_plus) - (ll)abs(min_minus) + (ll)abs(min_minus+min_plus) << std::endl;
        
    }
    
}
