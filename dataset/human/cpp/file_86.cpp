#include <iostream>
using namespace std;
int main(void){
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    
    int res=0,b;
    for(int r=0;r<=N/R;r++){
        for(int g=0;g<=N/G;g++){
            b = N - r*R - g*G;
            if(b>=0 && b%B==0){
                res++;
            }
        }
    }
    
    cout << res << endl;
    
}
