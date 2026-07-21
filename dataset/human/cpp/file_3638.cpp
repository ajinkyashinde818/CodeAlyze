#include<iostream>
#include<algorithm>
typedef long long ll;

using namespace std;

int N;
ll val;
int main() {
    cin>>N;
    ll sum=0;
    ll min_val=1e12;
    int ncnt=0;
    while(N--) {
        cin>>val;
        sum+=abs(val);
        min_val=min(min_val, abs(val));
        if(val<=0) ncnt++;
    }

    if(ncnt%2) {
        cout<<sum-2*min_val;
    } else {
        cout<<sum;
    }

}
