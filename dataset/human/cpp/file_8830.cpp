#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;

int main(){
    int N,M; cin>>N>>M;
    vector<string> A(N);
    vector<string> B(M);
    int count;
    for(int i=0;i<N;i++)cin>>A.at(i);
    for(int i=0;i<M;i++)cin>>B.at(i);
    for(int i=0;i<=N-M;i++){
        for(int j=0;j<=N-M;j++){
            count=0;
            for(int k=0;k<M;k++){
                if(B.at(k)==A.at(k+i).substr(j,M))count++;
            }
            if(count==M){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
