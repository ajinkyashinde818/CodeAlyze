#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int N;
    cin>>N;
    long as[N];
    long apsum[2][N];
    for(int i = 0; i < N; i++){
        cin>>as[i];
        apsum[0][i]=0;
        apsum[1][i]=0;
    }
    apsum[0][0]=as[0];//頭から0までの部分列和
    for(int i = 1; i < N; i++){//1から最後までの部分列和
        apsum[1][1] += as[i];
    }
    long ans = abs(apsum[0][0]-apsum[1][1]);
    for(int i = 1; i < N-1; i++){
        apsum[0][i]=apsum[0][i-1]+as[i];
        apsum[1][i+1]=apsum[1][i]-as[i];
        long tmp = abs(apsum[0][i]-apsum[1][i+1]);
        ans = ans>tmp ? tmp : ans;
    }
    cout<<ans<<endl;
    return 0;
}
