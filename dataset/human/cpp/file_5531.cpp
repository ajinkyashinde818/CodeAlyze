#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

int main()
{
    int n,r;
    cin>>n>>r;
    if(n<10)
    cout<<r+100*(10-n)<<endl;
    else
        cout<<r<<endl;
    return 0;
    
}
