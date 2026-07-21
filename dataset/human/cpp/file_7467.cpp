#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long N;
    cin>>N;
   vector<long long>cards(N);
    long long sum=0;
    for(long long i=0;i<N;i++){
        cin>>cards.at(i);
        sum+=cards.at(i);
        
    }
    //cout<<cards.at(1)<<endl;
    long long a_sum=0;
    vector<long long>results(N-1,9999);
    for(long long i =0;i<N-1;i++){
        a_sum+=cards.at(i);
        results.at(i)=abs(2*a_sum-sum);
        
        
    }
    sort(results.begin(),results.end());
    cout<<results.at(0)<<endl;
   
}
