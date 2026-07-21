#include <iostream>
using namespace std;

void run(int N, int R) {
    int innerRating = R;
    if(N < 10){
        // 内部レーティングは特殊計算のケース
        innerRating = R + 100 * (10 - N);
    }
    std::cout << innerRating << std::endl;
}

int main(){
    int a, b;
    std::cin >> a >> b;
    run(a, b);
}
