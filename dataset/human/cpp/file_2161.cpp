#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long n,minus_cnt=0,sum=0;
    vector<long> x;
    cin>>n;
    for(int i=0;i<n;i++){
        long buf;
        cin>>buf;
        if(buf<0) {
            buf*=-1;
            minus_cnt++;
        }
        x.push_back(buf);
        sum+=buf;
    }
    if(minus_cnt%2!=0){
        sort(x.begin(),x.end());
        sum-=x.at(0)*2;
    }  
    cout<<sum<<endl;
}
