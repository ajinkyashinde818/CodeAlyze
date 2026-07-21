#include<iostream>
using namespace std;

int main(){
    int R, G, B, N;
    cin >> R >> G >>B >>N;
    int count=0;
    int tempN,temptempN;
    for(int r=0; r<=N/R; r++){
        tempN =N;
        tempN -= R*r;
        if(tempN == 0){
            count++;
        }else{
            for(int g=0; g<=tempN/G; g++){
                temptempN = tempN;
                temptempN -= G*g;
                if(temptempN%B == 0){
                    count++;
                }
            }
        }
    }
    cout << count<< endl;
    return 0;
}
