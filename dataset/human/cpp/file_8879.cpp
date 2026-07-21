#include <iostream>

const int N = 51;

char map[N][N], map2[N][N];
int a, b;

bool contain(int x, int y){
    for(int h = 0; h < b; ++h){
        for(int w = 0; w < b; ++w){
            if(map[h + y][w + x] != map2[h][w])return false;
        }
    }
    return true;
}

int main(){
    std::cin >> a >> b;
   
    for(int i = 0; i < a; ++i){
        for(int j = 0; j < a; ++j){
            std::cin >> map[i][j];
        }
    }
    
    for(int i = 0; i < b; ++i){
        for(int j = 0; j < b; ++j){
            std::cin >> map2[i][j];
        }
    }
     
    for(int i = 0; i < a - b + 1; ++i){
        for(int j = 0; j < a - b + 1; ++j){
            if(contain(j, i)){
                std::cout << "Yes" << std::endl;
                return 0;
            }
        }
    }
    
    std::cout << "No" << std::endl;
    return 0;
}
