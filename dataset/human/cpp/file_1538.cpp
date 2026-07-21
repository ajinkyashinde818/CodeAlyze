#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;


int main() {
    

    long n;
    cin >> n;
    long i;
    for (i=1;i*(i+1) <=2*n; i++){
        if(i*(i+1) == 2*n){
            cout << "Yes" << endl;
            cout << i+1 << endl;
            const long I = i;
            long S[I+1][I];
            long mofu = 1;
            for (long j=0; j<I+1;j++ ){
                for (long k=0;k<I;k++){
                    if(k<j){
                        S[j][k] = S[k][j-1];
                    }else{
                        S[j][k] = mofu;
                        mofu += 1;
                    }
                }

            }
            for (long j=0;j<I+1;j++){
                cout << i;
                for (long k=0;k<I;k++){
                    cout << " " << S[j][k];
                }
                cout << endl;
            }
            goto Exit;
        }
    }
    cout << "No" << endl;
    Exit:
    ;


}
