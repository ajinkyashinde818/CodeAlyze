#include<bits/stdc++.h>
 
using namespace std;
 
long long freq[26];
 
int main()
{
    
    int n;
    cin>>n;
    string s;
    cin>>s;
 
    long long mod=1e9+7;
 
    for(int i=0;i<n;i++)
    {
        freq[s[i]-'a']++;
 
    }
 
    long long ans=1;
 
    for(int i=0;i<26;i++)
    {
        if(freq[i]!=0)
 
        {
            ans*=(freq[i]+1);
            ans%=mod;
        }
    }
    cout<<ans-1<<endl;
 
 
}
