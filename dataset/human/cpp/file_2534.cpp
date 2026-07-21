#include<iostream>
#include<vector>
using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

int main(){
    int N;cin>>N;
    vector<long long> a(N);
    for(int i=0;i<N;i++)cin>>a[i];
    int num_minus=0;
    long long mi=1LL<<60;
    long long sum=0;
    for(int i=0;i<N;i++){
        if(a[i]<0)num_minus++;
        chmin(mi,abs(a[i]));
        sum+=abs(a[i]);
    }
    if(num_minus %2==0)cout<<sum<<endl;
    else cout<<sum-mi*2<<endl;
}
