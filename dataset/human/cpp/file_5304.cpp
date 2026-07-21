#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
int main(){
    int N,R;
    cin>>N>>R;
    if(N>=10){
        cout<<R<<endl;
    }
    else{
        cout<<R+(10-N)*100<<endl;
    }
    return 0;
}
