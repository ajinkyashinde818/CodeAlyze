#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    int N,M;
    cin >> N >> M;
    vector<vector<bool>> a(N, vector<bool>(N,false));
    vector<vector<bool>> b(M, vector<bool>(M,false));

    char tmp;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> tmp;
            if(tmp == '#'){
                a.at(i).at(j) = '#';
            }
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            cin >> tmp;
            if(tmp == '#'){
                b.at(i).at(j) = '#';
            }
        }
    }

    for(int i = 0; i <= N - M; i++){
        for(int j = 0; j <= N - M; j++){
            //cout << i << "," << j << endl;
            bool check = true;
            for(int k = 0; k < M; k++){
                for(int l = 0; l < M; l++){
                    check &= (a.at(i+k).at(j+l) == b.at(k).at(l));
                }
            }
            if(check){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
