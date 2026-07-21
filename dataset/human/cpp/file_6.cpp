typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main() {
    ll r,g,b,n;
    std::cin >> r>>g>>b>>n;
    
    ll result = 0;
    
    for (int i = 0; i <= 3000; i++) {
        for (int j = 0; j <= 3000; j++) {
            if( n-(i*r+j*g) >= 0 &&  (n-(i*r+j*g)) % b == 0 ){
                // std::cout << i<<" "<<j<<" "<<n-(i*r+j*g)<< std::endl;
                // std::cout << i<<" "<<j<<" "<<(n-(i*r+j*g))/b<< std::endl;
                result++;
            }
        }
    }
    std::cout << result << std::endl;
}
