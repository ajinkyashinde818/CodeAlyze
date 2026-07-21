#include <iostream>
using namespace std;
int main(void){
    int R,G,B,n;
    
    cin >> R >> G >> B >> n;
    
    int res = 0;
    
    for(int r = 0; r <= 3000; r++){
        for(int g = 0; g <= 3000; g++){
            int b = (n-(r*R+g*G))/B;
            
            if(b >= 0){
                if(r*R+g*G+b*B==n) res++;
            }
        }
    }
    cout << res << endl;
}
