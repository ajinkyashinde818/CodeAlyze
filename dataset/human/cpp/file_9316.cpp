//
// Created by yuu on 2019-04-26.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <math.h>
#include <stack>
#include <queue>

using namespace std;


int main(void){
    int N,M;
    string A[60];
    string B[60];

    cin>>N>>M;

    for (int i = 0; i < N; ++i) {
        cin>>A[i];
    }

    for (int i = 0; i < M; ++i) {
        cin>>B[i];
    }
    bool flag=false;
    for(int i=0; i<=N-M; i++){
        for (int k = 0; k <= N-M; ++k) {
            if(A[i].substr(k,M) == B[0]){
                flag = true;
                for (int j = 0; j < M; ++j) {
                    if(A[i+j].substr(k,M) != B[j]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                break;
            }
        }

        if(flag){
            break;
        }
    }



    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
