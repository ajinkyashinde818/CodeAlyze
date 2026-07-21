#include <bits/stdc++.h>
using namespace std;

int main(){
   
    int N;
    cin>>N;
    vector<int> S(N,0);
    for(int i=0;i<N;i++){
        cin>>S[i];
    }
    sort(S.begin(),S.end());
    long long int sum=0;
    if(N%2==0){
    for(int i=0;i<N;i+=2){
        if(S[i]+S[i+1]<=0){
            sum+=(-S[i]-S[i+1]);
        }
        else sum+=(S[i]+S[i+1]);
    }
    }
    else{
        for(int i=0;i<N-1;i+=2){
            if(S[i]+S[i+1]<=0){
                sum+=(-S[i]-S[i+1]);
            }
            else sum+=(S[i]+S[i+1]);
        }
        sum+=S[N-1];
    }
    cout<<sum<<endl;
}
