#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,a;
    cin>>n;
    std::deque<int> deq;
    long long int sum=0;
    for (int i=0;i<n;i++) {
        cin>>a;
        deq.emplace_back(a);
        sum+=a;
    }
    long long int ans=0;
    long long int min=1000000000000;
    for (int j=0;j<n-1;j++) {
        ans+=deq[j];
        long long int tmp=abs(ans-(sum-ans));
        if (tmp<min) {
            min=tmp;
        }
    }
    cout<<min<<endl;
}
