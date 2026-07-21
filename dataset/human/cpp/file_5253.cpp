#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N,R;
    cin>>N>>R;
    if(N>=10) cout<<R<<endl;
    else cout<<(R+100*(10-N))<<endl;
    return 0;
}
