#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    int r, g, b, n;
    std::cin >> r >> g >> b >> n;

    int count = 0;
    int iLimit = n / r;
    for(int i = 0; i <= iLimit; ++i){
        int jLimit = (n - i * r) / g;
        for(int j = 0; j <= jLimit; ++j){
            if(0 == (n - i * r - j * g) % b){
                ++count;
            }
        }
    }
    
    std::cout << count << std::endl;

    return 0;
}
