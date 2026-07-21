#include <iostream>
using namespace std;

int main(void){
    int n;
    int ball[3];    
    cin >> ball[0] >> ball[1] >> ball[2] >> n;
    int cnt=0;
    for(int i=0;i<=int(n/ball[0]);i++){
        for(int j=0; j<=n/ball[1];j++){
            // cout << i << ' ' << j << endl;
            if(0<=(n-ball[0]*i-ball[1]*j) and (n-ball[0]*i-ball[1]*j)%ball[2]==0){
                cnt+=1;
            }
        }
    }
    cout << cnt;
}
