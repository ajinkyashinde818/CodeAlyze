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
    long N;
    std::cin >> N;
    std::vector<long> A;
    long minuscount=0;
    for(long i=0; i<N; i++){
        long temp;
        std::cin >> temp;
        if(temp<0){
            minuscount++;
            temp=(-1)*temp;
        }
        A.push_back(temp);
    }
    std::sort(A.begin(),A.end());
    if(minuscount%2==1){
        A[0]=A[0]*(-1);
    }

    long result=0;
    for(long i=0; i<N; i++){
        result+=A[i];
    }
    std::cout << result << std::endl;
    return 0;
}
