#include<iostream>
using namespace std;

// Problem https://atcoder.jp/contests/diverta2019/tasks/diverta2019_b

int solver(int rCntPB,int gCntPB,int bCntPB,int allB){
    int rmax = allB / rCntPB;
    int gmax = allB / gCntPB;

    int result = 0;
    for(int r=0;r <= rmax;r++){
        for(int g=0;g <= gmax;g++){
            int remain = allB - r*rCntPB - g * gCntPB;
            int bModQ = remain % bCntPB;
            if( 0 <= remain and bModQ == 0){
                result = result + 1;
            }
        }
    }
    return result;
}

int main(void){
    int R,G,B,N,answer;
    cin >> R >> G >> B >> N;
    answer = solver(R,G,B,N);
    cout << answer << endl;
}
