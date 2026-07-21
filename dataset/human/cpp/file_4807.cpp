#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
   int n,r,p,result;

   cin>>n>>r;
   if(n>=10){
    cout<<r<<endl;
   }
   else{
        p=100*(10-n);
        result=p+r;
        cout<<result<<endl;
   }

    return 0;
}
