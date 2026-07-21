#include <bits/stdc++.h>

int main(){
    int N, M;
    std::cin >> N >> M;
    std::vector< std::vector< bool > >A(N, std::vector< bool >(N));
    for(int i=0; i<N; i++){
        std::string tmp;
        std::cin >> tmp;
        for(int j=0; j<N; j++){
            if(tmp[j] == '.'){
                A[i][j] = true;
            }else{
                A[i][j] = false;
            }
        }
    }
    std::vector< std::vector< bool > >B(M, std::vector< bool >(M));
    for(int i=0; i<M; i++){
        std::string tmp;
        std::cin >> tmp;
        for(int j=0; j<M; j++){
            if(tmp[j] == '.'){
                B[i][j] = true;
            }else{
                B[i][j] = false;
            }
        }
    }
    
    for(int i=0; i<N-M+1; i++){
        for(int j=0; j<N-M+1; j++){
            bool find = true;
            for(int a=0; a<M; a++){
                for(int b=0; b<M; b++){
                    if(A[a+i][b+j] != B[a][b]){
                        find = false;
                        break;
                    }
                }
                if(!find){
                    break;
                }
            }
            if(find){
                std::cout << "Yes" << std::endl;
                return 0;
            }
        }
    }
    
    std::cout << "No" << std::endl;
    
    return 0;
    
}
