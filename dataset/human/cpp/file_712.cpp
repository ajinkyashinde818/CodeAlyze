#include<stdio.h>
#include<iostream>
using namespace std;

int R,G,B,N;
int main (){
    cin >> R >> G >> B >> N;
    int ans = 0;
    for(int r=0; r<=N;r+=R) {
        for(int g=0; g<=N-r;g+=G) {   
            if ( (N - (r + g)) % B == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
