#include <bits/stdc++.h> 
using namespace std;
const long INF=1000000000000000;
const long MOD=1000000007;

int main(){
    long N;
    cin>>N;
    string s;
    cin>>s;
    
    vector<bool> start(2*N);
    start.at(0)=true;
    bool nowb=true;
    for(int i=1;i<2*N;i++){
        //cout<<nowb<<" "<<s.at(i)<<endl;
        if((nowb&& s.at(i)=='W')||((!nowb)&& s.at(i)=='B')){
            
            start.at(i)=true;
        }else{
            start.at(i)=false;
        }
        nowb=(!nowb);
    }
    
    long ans=1,count=1;
    
    for(int i=1;i<2*N;i++){
        if(start.at(i)){
            //cout<<"#"<<endl;
            count++;
        }else if(count<=0){
            cout<<0<<endl;
            return 0;
        }else{
            //cout<<"&"<<endl;
            ans*=count;
            ans%=MOD;
            count--;
        }
    }
    
    //cout<<count<<endl;
    
    if(count>0){
        cout<<0<<endl;
        return 0;
    }
    
    long kaizyo=1;
    for(long i=1;i<=N;i++) kaizyo=(kaizyo*i)%MOD;
    
    cout<<(ans*kaizyo)%MOD<<endl;
}
