#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    string a[N];
    string b[M];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < M; i++){
        cin >> b[i];
    }
    for(int i = 0; i <= N - M; i++){
        for(int j = 0; j <= N - M; j++){
            // check start
            int ok = 1;
            for(int k = 0; k < M; k++){
                for(int l = 0; l < M; l++){
                    if(a[i+k][j+l] != b[k][l]){
                        ok = 0;
                        break;
                    }
                }
                if(ok == 0){
                    break;
                }
            }
            if(ok == 1){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
