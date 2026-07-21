#include<iostream>

using namespace std;
int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    long int sum=0;
    int num=0, p=1000000000, neg=-1000000000;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=0)
        {
            num++;
            sum+= -a[i];

            if(a[i]>neg)
                neg = a[i];
        }
        else
        {
            sum+=a[i];

            if(a[i]<p)
                p = a[i];
        }  
    }

    if(num%2==1)
    {
        if(-neg>p)
        {
            sum -= p*2;
        }
        else
        {
            sum += neg*2;
        }    
    }

    cout<<sum;
}
