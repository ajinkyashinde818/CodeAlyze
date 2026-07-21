#include <iostream>
#include<bits/stdc++.h>
using namespace std;
map<int ,int>mp;
const int N=10E5+5;
vector<int>vc;
long long int arr[N];
int main() {


long long n;
cin>>n;
long long sum2=0;
int neg=0;
long long mini=1e18;
for(int i=0;i<n;i++){cin>>arr[i]; if(arr[i]<0)neg++; sum2+=abs(arr[i]);}
for(int i=0;i<n;i++)
{
    //sum2+=abs(arr[i]);
    if(arr[i]<0 )
    {
        arr[i]=-1*arr[i];

    }

}
for(int i=0;i<n;i++)mini=min(mini,arr[i]);

if(neg%2==0){cout<<sum2; return 0;}
bool reham=true;
long long sum=0;
for(int i=0;i<n;i++)
{
    if(arr[i]==mini && reham==true)
    {
        reham=false;
        continue;

    }
    else sum+=arr[i];
}

cout<<sum-mini;

}
