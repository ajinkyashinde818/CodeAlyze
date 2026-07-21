#include<iostream>
#include<vector>
using namespace std;


int main(){
    int N,M;
    cin>>N>>M;
    vector<string> vecA(N);
    vector<string> vecB(M);

    for(auto &x:vecA)cin>>x;
    for(auto &x:vecB)cin>>x;

    for(int i=0;i<=N-M;++i){
        for(int k=0;k<=N-M;++k){
            bool temp=false;
            
            if(vecA[i][k]==vecB[0][0]){
                temp=true;
                for(int n=0;n<M;++n){
                    for(int m=0;m<M;++m){
                        if(m+k>=N||n+i>=N||vecA[i+n][k+m]!=vecB[n][m]){
                            temp=false;
                        }
                    }
                }
            }
            if(temp){
                cout<<"Yes"<<endl;
                return 0;
            }
                
        }
    }

    cout<<"No"<<endl;


}
