#include<iostream>
#include<string>
#include<vector>

int main(){

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    std::vector<std::string> b(m);

    for(auto&& e : a){
        std::cin >> e;
    }

    for(auto&& e : b){
        std::cin >> e;
    }

    for(size_t i = 0; i <= n - m; i++){
        for(size_t j = 0; j <= n - m; j++){
            bool flag = true;
            for(size_t k = 0; k < m; k++){
                for(size_t l = 0; l < m; l++){
                    if(a[i + k][j + l] != b[k][l]) flag = false;
                }
            }
            if(flag == true){
                std::cout << "Yes" << std::endl;
                return 0;
            }  
        }
    }

    std::cout << "No" << std::endl;
    
    return 0;
}
