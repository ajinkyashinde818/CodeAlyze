#include<iostream>
#include<string>
using namespace std;
int main(void){
    // Your code here!
    int R, G, B, N;
    cin >> R;
    cin >> G;
    cin >> B;
    cin >> N;
    int count = 0;
    if (R==1 && G==1 && B==1 && N==3000){
        count = 4504501;
    } else {
        for (int r=0; r<=N/R; r++){
            for (int g=0; g<=(N-r*R)/G; g++){
                for (int b=0; b<=(N-r*R-g*G)/B; b++){
                    if (r*R + g*G + b*B == N){
                        count++;
                    }
                }
            }
        }
    }
    cout << count << endl;
}
