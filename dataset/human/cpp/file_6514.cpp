#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>
#include <numeric>

using namespace std;

const int MOD = 1e9 + 7;

int main(){

    int N;
    cin >> N;
    string S;
    cin >> S;

    if(S[0] == 'W'){
        cout << 0 << endl;
        return 0;
    }

    int cntOut = 1;
    int cntIn = 0;
    long long ans = 1;
    for(int i = 1; i < 2 * N; i++){
        
        char temp2 = S[i];
        bool in;
        if(i % 2 == 1){
            if(temp2 == 'W'){
                cntOut++;
                in = false;
            }
            else{
                cntIn++;
                in = true;
            }
        }
        else
        {
            if(temp2 == 'B'){
                cntOut++;
                in = false;
            }
            else{
                cntIn++;
                in = true;
            }
        }
        
        if(cntIn > cntOut){
            cout << 0 << endl;
            return 0;
        }

        if(in){
            ans = (ans * (cntOut - cntIn + 1)) % MOD;
        }
    }

    if(cntIn == cntOut){

        long long C = 1;
        for(int i = 2; i <= N; i++){
            C = (C * i) % MOD;
        }

        ans = (ans * C) % MOD;

        cout << ans << endl;
    }
    else{
        cout << 0 << endl;
    }

    return 0;
}
