typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll n;

ll table[600][600];

int main() {
    std::cin >> n;
    if( ( (ll)sqrt(1+8*n) ) * ( (ll)sqrt(1+8*n) ) != 1+8*n  ){
        std::cout << "No" << std::endl;
    }else{
        ll count =1;
        for (int i = 0; i < 590; i++) {
            for (int j = 0; j <= i; j++) {
                table[j][i] = count;
                count++;
            }
        }
        std::cout << "Yes" << std::endl;
        ll k = ((ll)sqrt(1+8*n)+1)/2;
        std::cout << k << std::endl;
        for (int i = 0; i <= k-2; i++) {
            std::cout << k-1;
            
            for (int j = 0; j <= k-2; j++) {
                std::cout <<" "<< table[min(i,j)][max(i,j)];
            }
            std::cout << std::endl;
        }
        std::cout << k-1;
        for (int j = 0; j <= k-2; j++) {
            std::cout <<" "<< table[j][j];
        }
        std::cout << std::endl;
        
    }
}
