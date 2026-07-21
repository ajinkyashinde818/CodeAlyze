#include <iostream>
using namespace std;

int r,g,b,n;
int res = 0;
int main()
{
    cin>>r>>g>>b>>n;
    for(int x1 = 0;x1<3001;x1++)
        for(int x2 = 0;x2<3001;x2++){
            if(x1*r+x2*g<=n && (n-x1*r-x2*g)%b==0)
                res+=1;
        }
    cout<<res<<endl;
}
