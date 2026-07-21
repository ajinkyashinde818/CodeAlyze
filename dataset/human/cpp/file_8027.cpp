#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;

    std::vector<long long> a(n), b(n);
    std::cin >> a.at(0);
    b.at(0) = a.at(0);
    for(int i = 1; i < n; ++i){
        std::cin >> a.at(i);
        b.at(i) = a.at(i) + b.at(i - 1);
    }

    std::vector<long long> c(n - 1);
    for(int i = 0; i < n - 1; ++i){
        c.at(i) = std::abs(b.at(n - 1) - 2 * b.at(i));
    }

    std::cout << *min_element(c.begin(), c.end()) << std::endl;

    return 0;
}
