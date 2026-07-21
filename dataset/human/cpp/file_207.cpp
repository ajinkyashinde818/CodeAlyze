#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int r=0;
    for(int i=0; i<=N/R; i++){
        for(int j=0; j<=N/G; j++){
            if(N-i*R-j*G>=0 && (N-i*R-j*G)%B==0)r++;
        }
    }
    cout << r <<"\n";
}
