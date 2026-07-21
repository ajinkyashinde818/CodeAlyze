#include<iostream>
using namespace std;

int main(){
    int R,G,B,N;
    int sr,sg,sb,c;
    cin >> R;
    cin >> G;
    cin >> B;
    cin >> N;
    for (int i=0;i<int(N/R+1);i++){
        int sr = i*R;
        for (int j=0;j<int((N-i*R)/G)+1;j++){
            sg = j * G;
            if (sr + sg <= N) {
                sb = N - sr - sg;
                if (sb % B == 0) {c++;}
            }
        }
    }
    cout << c;
    return 0;
}
