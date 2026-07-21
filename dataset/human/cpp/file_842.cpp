#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,R,G,B;
    cin >> R >> G >> B >> N;
    int count = 0;

    for(int i =0; R*i <= N; i++){
        for(int j = 0; R*i+G*j <= N; j++){
            if( (N-(R*i + G*j))%B == 0 ){
                count ++;
            }
        }
    }

    cout << count << endl;
    
}
