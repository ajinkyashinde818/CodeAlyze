#include<bits/stdc++.h>
using namespace std;

const int N=1e6+30;
typedef long long ll;
int n,d;
int main()
{
    cin>>n>>d;
    if(n>=10){
        cout<<d<<endl;
    }
    else{
        int tmp=100*(10-n);
        cout<<d+tmp<<endl;
    }
}
