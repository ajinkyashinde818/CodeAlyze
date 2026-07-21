#include<iostream>

using namespace std;

int box(int r,int g,int b,int N){
    int count = 0;
    for (int  i = 0; i < N/r+1; i++){
        for (int  j = 0; j < (N-i*r)/g+1; j++){
            if((N-(i*r+j*g))%b == 0)
                count++;
        }
    }
    return count;
}


int main(){
    int N,R,G,B;
    cin >> R >> G >> B >> N;

    cout << box(R,G,B,N) << endl;

    return 0;

}
