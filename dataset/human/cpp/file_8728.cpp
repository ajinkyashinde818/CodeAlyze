#include<iostream>
#include<string>
#include <cmath>
#include <ctype.h>
#include<vector>
using namespace std;
int N, M;
vector<string> A;
vector<string> B;

int main() {
    cin >> N >> M;
    cin.ignore();
    for(int i=0; i<N; ++i){
        string str; 
        getline(cin, str);
        A.push_back(str);
    }
    for(int i=0; i<M; ++i){
        string str; 
        getline(cin, str);
        B.push_back(str);
    }
    bool flag=false;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(i+M-1>=N or j+M-1>=N) continue;
                bool match=true;
                for(int k=0; k<M; ++k){
                    for(int l=0; l<M; ++l){
                        if(B[k][l]!=A[i+k][j+l]) match = false;
                    }
                }             
                if(match) flag = true;
        }
    }
    if(flag) cout <<"Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
