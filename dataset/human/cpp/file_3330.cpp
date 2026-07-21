#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int N;
    cin>>N;
    int A[100010];
    int mi=0;
    int small=1000000000;
    unsigned long sum=0;
    for(int i=0;i<N;++i){
        cin>>A[i];
        sum+=abs(A[i]);
        if(A[i]<0){
            mi++;
        }
        if(small>abs(A[i])){
            small=abs(A[i]);
        }
    }
    if(mi%2==0)cout<<sum<<endl;
    else cout<<sum-small-small<<endl;
}
