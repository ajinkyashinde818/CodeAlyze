#include<iostream>
using namespace std;

int main(){
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    long count = 0;

    for(int r=0;r<=3000;r++){
        for(int g=0;g<=3000;g++){
            int brest = N - r*R - g*G;
            if(brest >= 0 && brest%B == 0){
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
