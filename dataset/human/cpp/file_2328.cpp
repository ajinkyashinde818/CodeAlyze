#include <bits/stdc++.h>
using namespace std;
//関数
const long INF=100000000000;

void display(long j,vector<long> x){
    cout<<"data "<<j<<" display_start"<<endl;
    for(int i=0;i<x.size();i++){
        cout<<x.at(i)<<" ";
    }
    cout<<endl<<"display_end"<<endl<<endl;
}


//main
int main() {
    
    //入力
    long N;
    cin>>N;
    vector<long> A(N);
    for(int i=0;i<N;i++){
        cin>>A.at(i);
    }
    
    
    //計算
    long minimal =INF;
    long sum=0;
    bool odd=false;
    for(int i=0;i<N;i++){
        minimal=min(abs(A.at(i)),minimal);
        sum+=abs(A.at(i));
        if(A.at(i)<0) odd=(!odd);
    }
    
    
    //出力
    cout<<sum-(odd)*2*minimal<<endl;
}
