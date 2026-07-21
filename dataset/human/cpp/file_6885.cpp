#include <iostream>
#include <string>
#include <vector>
#include <queue>
using ll=long long;
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> A(N);
    vector<int> B(N);

    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int j=0;j<N;j++){
        cin>>B[j];
    }


/*
    int apt=0;
    int bpt=0;
    int maxD=0;
    int cnt;
    for(int i=1;i<=N;i++){
        cnt=0;
        while(apt<N && A[apt]<=i){
            apt++;
            cnt++;
        }
        if(maxD<(apt-bpt)){
            maxD=(apt-bpt);
        }
        while(bpt<N && B[bpt]<=i){
            bpt++;
            cnt++;
        }
        if(cnt>N){
            cout<<"No"<<endl;
            return 0;
        }
    }
    */

    vector<int> C(N+1,0);
    vector<int> D(N+1,0);
    for(int i=0;i<N;i++){
        C[A[i]]++;
        D[B[i]]++;
    }
    for(int i=1;i<N+1;i++){
        if(C[i]+D[i]>N){
            cout<<"No"<<endl;
            return 0;
        }
    }
    for(int i=1;i<N+1;i++){
        C[i]+=C[i-1];
        D[i]+=D[i-1];
    }

    int maxD=0;
    for(int i=1;i<N+1;i++){
        if(maxD<C[i]-D[i-1]){
            maxD=C[i]-D[i-1];
        }
    }

    cout<<"Yes"<<endl;


    for(int i=0;i<N;i++){
        cout<<B[(i+N-maxD)%N]<<" ";
    }
    cout<<endl;

    return 0;
}
