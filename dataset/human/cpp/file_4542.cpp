#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long ll;
ll a,b;
int main(){
    cin>>a>>b;
    if(a>=10) cout<<b<<endl;
    else cout<<b+100*(10-a)<<endl;

    return 0;
}
