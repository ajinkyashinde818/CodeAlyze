#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;cin>>N;
    vector<int>V(N);
    long long sum=0;
    long long m=100000000;
    int count=0;
    for(int i=0;i<N;i++){
        cin>>V[i];
        if(m>abs(V[i]))m=abs(V[i]);
        if(V[i]<0)count++;
        sum+=abs(V[i]);
    }
    if(count%2==0)cout<<sum;
    else cout<<sum-2*m<<endl;
}
