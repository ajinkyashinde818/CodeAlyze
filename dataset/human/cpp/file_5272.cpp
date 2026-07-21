#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e;
string s,h;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>a>>b;
    if(a>=10){
        cout<<b;
    }else{
        cout<<b+(10-a)*100;
    }
    return 0;
}
