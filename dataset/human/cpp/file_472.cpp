#include <vector>
#include <iostream>
using namespace std;


void a(){
    int N,K; cin >> N >> K;

    cout << N - K + 1;

}

void b(){
    int R,G,B,N; cin >> R >> G >> B >> N;

    int count = 0;
    for(int r = 0; r*R <= N; r++)
        for(int g = 0; r*R + g*G <= N; g++){
            int rg = r*R + g*G;
            if ((N - rg) % B == 0){
                count++;
            }
        }

    cout << count;

}

int main(){

    b();
    return 0;


}
