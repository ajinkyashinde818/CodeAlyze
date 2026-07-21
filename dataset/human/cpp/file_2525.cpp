#include <bits/stdc++.h>

int main(){
    int N;
    std::cin >> N;
    std::vector< int > A(N);
    for(int i=0; i<N;i++){
        std::cin >> A[i];
    }
    
    long long sum = 0;
    int min = 1e9;
    bool odd = false;
    for(int i=0; i<N;i++){
        if(A[i] < 0){
            A[i] *= -1;
            odd = odd ^ 1;
        }
        sum += A[i];
        if(min > A[i]){
            min = A[i];
        }
    }
    
    if(odd){
        sum -= 2 * min;
    }
    std::cout << sum << std::endl;
    
    
    
    return 0;
}
