#include <iostream>
using namespace std;
int main()
{
    long int r, g, b, n, sum=0, i, j;
    cin>>r>>g>>b>>n;
    for(i=0;i*r<=n;i++){
        for(j=0;j*g<=n;j++){
            if(n-i*r-g*j>=0&&(n-i*r-g*j)%b==0)
                sum++;
        }
    }
    cout<<sum<<endl;
}
