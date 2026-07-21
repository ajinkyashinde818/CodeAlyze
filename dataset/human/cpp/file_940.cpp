#include <iostream>

using namespace std;

int main()
{
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    long long int ans=0;
    cin>>a>>b>>c>>d;
    for(int i=0;i<=3000;i++)
    {
        if(a*i>d)
            break;
        for(int j=0;j<=3000;j++)
        {
            if(a*i+b*j>d)
                break;
            if((d-a*i-b*j)%c==0)
                ans++;
        }

    }



    cout<<ans;



    return 0;
}
