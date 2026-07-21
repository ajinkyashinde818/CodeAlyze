#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{long long int n,r,sum=0,subsum=0,o=0,k,l,yy=0;
    vector <long long int > y;
   cin>>n;
    for(int i=0;i<n;i++){cin>>r,y.push_back(r);sum+=r;}
    for(int i=0;i<n-1;i++)
    {subsum+=y[i];
    l=sum-subsum;
    k=subsum-l;
if(yy==0){o=abs(k);yy++;}
        o=min(o,abs(k));
}
cout<<o;
    return 0;
}
