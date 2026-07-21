#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    vector<long long int>v(n);
    for(long long int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    long long int sum=0;
    for(long long int i:v)
        sum+=i;
    long long int min=INT_MAX;
    long long int first=0;
    for(long long int i=0;i<n-1;i++)
    {
        first+=v[i];
        sum-=v[i];
        if(min>abs(first-sum))
        {
            min=abs(first-sum);
        }
    }
    cout<<min;
}
