#include <bits/stdc++.h>
using namespace std;
const long long INFL=1LL << 60;
const long long INF=1<<29;

int main() {
    int N;
    cin >>N;
    vector<long long> A(N);
    int plus=1;
    cin>>A.at(0);
    long long ans=abs(A.at(0));
    long long Amin=abs(A.at(0));
    for(int i=1;i<N;i++){
        long long temp;
        cin >>temp;
        if(temp<0){
            temp=-temp;
            plus=1-plus;
        }
        ans+=temp;
        Amin=min(Amin,temp);
    }
    if((A.at(0)>=0)==plus) cout <<ans<<endl;
    else cout << ans-2*min(abs(A.at(0)),Amin);
    
    return 0;
}
