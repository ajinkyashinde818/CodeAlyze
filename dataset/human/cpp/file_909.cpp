#include <iostream>
using namespace std;
int main(void){
    int R, G, B, N, tmp, count=0;
    cin >> R >> G >> B >> N;
    
    for(int i=0; R*i<=N; i++){
        for(int j=0; R*i + G*j<=N; j++){
            tmp = N - (R*i + G*j);
            if(tmp % B == 0)
            count++;
        }
    }
    
    cout << count << "\n";
}
