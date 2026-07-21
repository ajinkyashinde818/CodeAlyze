#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    int R, G, B, N, count{0};
    cin >> R >> G >> B >> N;
    for(int r{0}; r<=N/R; ++r){
        for(int g{0}; g<=N/G; ++g){
            if((N-(R*r+G*g))>=0 and (N-(R*r+G*g))%B==0){
                ++count;
            }
        }
    }
    cout << count << endl;

}
