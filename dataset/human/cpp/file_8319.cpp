#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <deque>
#include <climits> 

int main()
{
    long N,M;
    std::cin >> N >> M;
    std::vector<std::string> A,B;
    for(long i=0; i<N; i++){
        std::string temp;
        std::cin >> temp;
        A.push_back(temp);
    }
    for(long i=0; i<M; i++){
        std::string temp;
        std::cin >> temp;
        B.push_back(temp);
    }

    bool flag=false;
    long count=0;
    for(long i=0; i<N-M+1; i++){
        for(long j=0; j<N-M+1; j++){
            count=0;
            for(long k=0; k<M; k++){
                for(long l=0; l<M; l++){
                    if(A[i+k][j+l]==B[k][l]){
                        count++;
                    }
                    if(count==M*M){
                        flag=true;
                    }
                }
            }
        }
    }
    if(flag){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }
    return 0;
}
