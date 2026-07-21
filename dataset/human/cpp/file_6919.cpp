#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void inp(vector <ll> &a,int n)
{
    for(int i=0;i<n;i++)
    cin>>a[i];
}
void out(int a[],int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
void change(int b[],int n,vector <int> &f,vector <int> &s)
{
    while(f.size()&&s.size())
    {
        int fi=f[f.size()-1];
        f.pop_back();
        int si=s[s.size()-1];
        s.pop_back();
        swap(b[fi],b[si]);
    }
    return;
}
int changef(int a[],int b[],int n,vector <int> &rem,int ele)
{
    for(int i=0;i<n&&rem.size();i++)
    {
        if(a[i]!=ele&&b[i]!=ele)
        {
            swap(b[i],b[rem[rem.size()-1]]);
            rem.pop_back();
        }
    }
    if(rem.size()!=0)
        return 0;
    return 1;
}
void solve()
{
  int n;
  cin>>n;
  int a[n],b[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  for(int i=0;i<n;i++)
    cin>>b[i];
  vector <int> itos[n+1];
  vector <int> etos;
  unordered_map <int,int> m;
  for(int i=0;i<n;i++)
  {
     if(a[i]==b[i])
     {
         itos[a[i]].push_back(i);
         if(m[a[i]]==0)
         {
             etos.push_back(a[i]);
         }
         m[a[i]]++;
     }
  }
  if(etos.size()==0)
  {
      cout<<"Yes"<<endl;
      out(b,n);
      return;
  }
  if(etos.size()>1)
  {
    int rem=etos[etos.size()-1];
    etos.pop_back();
    while(etos.size()!=0)
    {
        int temp=etos[etos.size()-1];
        etos.pop_back();
        change(b,n,itos[temp],itos[rem]);
        if(itos[temp].size()==0&&itos[rem].size()==0)
        {
            if(etos.size()==0)
            {
                cout<<"Yes"<<endl;
                out(b,n);
                return;
            }
            else{
                rem=etos[etos.size()-1];
                etos.pop_back();
            }
        }
        else if(itos[temp].size()==0)
        {}
        else{rem=temp;}

    }
    etos.push_back(rem);
  }
  int x=changef(a,b,n,itos[etos[etos.size()-1]],etos[etos.size()-1]);
  if(x==0)
    cout<<"No"<<endl;
  else{
    cout<<"Yes"<<endl;
    out(b,n);
    return;
  }
 return;
}
int main() {
    ll t=1;
    //cin>>t;
    while(t--)
    {
       solve();
    }
	return 0;
}
