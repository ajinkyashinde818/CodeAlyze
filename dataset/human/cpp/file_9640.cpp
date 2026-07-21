#include<iostream>
#include<string>
#include<vector>

int main(){
  int N, M;
  std::cin >> N >> M;
  std::vector<std::string> A(N), B(M);
  for(int i = 0; i < N; i++) std::cin >> A.at(i);
  for(int i = 0; i < M; i++) std::cin >> B.at(i);
  bool isIncluded = false;
  for(int i = 0; i < N - M + 1; i++){
    for(int j = 0; j < N - M + 1; j++){
      for(int k = 0; k < M; k++){
        bool isBiEqualAi = true;
        for(int l = 0; l < M; l++){
          if(B.at(k).at(l) != A.at(i + k).at(j + l)){
            isBiEqualAi = false;
            break;
          }
        }//l
        if(isBiEqualAi){
          if(k == M - 1){
            isIncluded = true;
            break;
          }else continue;
        }else break;
      }//k
      if(isIncluded) break;
    }//j
    if(isIncluded) break;
  }//i
  if(isIncluded) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
}
