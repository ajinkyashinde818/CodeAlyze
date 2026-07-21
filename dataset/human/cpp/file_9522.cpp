#include<iostream>
#include<vector>
#include<string>

using pix = std::vector<std::string>;

int main(){
    int N, M;
    std::cin >> N >> M;
    pix A(N), B(M);
    for(int i = 0; i < N; i++){
        std::cin >> A[i];
    }
    for(int i = 0; i < M; i++){
        std::cin >> B[i];
    }

    // 左上の位置(x, y)を決める
    for(int x = 0; x + M <= N; x++){
        for(int y = 0; y + M <= N; y++){
            // 探索開始
            bool flag = true;
            for(int i = 0; i < M; i++){
                for(int j = 0; j < M; j++){
                    if(A[i + x][j + y] != B[i][j]){
                        flag = false;
                        break;
                    }
                }

                if(!flag) break;
            }

            if(flag){
                std::cout << "Yes" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "No" << std::endl;

    return 0;
}
