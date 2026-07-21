#include <iostream>
#include <vector>
#include <string>

int main()
{
    uint32_t nn;
    uint32_t rr;
    std::cin >> nn >> rr;
    if(nn <= 10){
        std::cout << (rr + 100*(10 -nn)) << std::endl;
    }else{
        std::cout << rr << std::endl;
    }
    return 0;
}
