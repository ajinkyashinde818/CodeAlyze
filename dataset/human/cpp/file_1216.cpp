#include<iostream>

int main(){

    size_t r, g, b, n;
    std::cin >> r >> g >> b >> n;

    size_t cnt = 0;

    for(size_t i = 0; i <= 3000; i++){
        for(size_t j = 0; j <= 3000; j++){
            if(i * r + j * g <= n){
                if((n - (i * r + j * g)) % b == 0){
                    cnt++;
                }
            }
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}
