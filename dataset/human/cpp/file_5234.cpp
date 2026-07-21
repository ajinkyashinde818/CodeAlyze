#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>


int main()
{
    long N,R;
    std::cin >> N >> R;
    if(N<10){
        std::cout << R+100*(10-N) << std::endl;
    }else{
        std::cout << R << std::endl;
    }
    return 0;
}
