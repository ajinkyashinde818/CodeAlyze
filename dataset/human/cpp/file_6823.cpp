/*
Reference : https://www.geeksforgeeks.org/maximum-product-subsequence-size-k/
 
 
*/
#include <bits/stdc++.h> 
using namespace std; 
 
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 
bool sortinrev(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
} 
bool sortbysecdesc(const pair<int,int> &a, 
                   const pair<int,int> &b) 
{ 
       return a.second>b.second; 
} 
 
/*
Mistakes
 
- while using pairs make sure you comparator datatype it's int by default change it as per the need
- Modify comparator if you want to
*/
#define f first
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll64 int64_t
#define pb push_back
#define pll pair<long long int,long long int>
#define pi pair<int,int>
#define mi map<int,int>
#define ll long long int
#define mll map<long long int,long long int>
#define umi unordered_map<int,int>
#define umll unordered_map<long long int,long long int>
#define vpi vector<pair<int,int>>
#define vpll vector<pair<long long int,long long int>>
#define mod 1000000007
#define fp(i,x,n) for(int i=x;i<n;i++)
#define fn(i,x,n) for(int i=x;i>n;i--)
#define fpm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define asort_vp_second(vect) sort(vect.begin(), vect.end(), sortbysec)
#define asort_vp_first(vect) sort(vect.begin(), vect.end())
#define dsort_vp_first(vect) sort(vect.begin(), vect.end(), sortinrev) 
#define dsort_vp_second(vect) sort(vect.begin(), vect.end(), sortbysecdesc)
#define vi vector<int>
#define vll vector<long long int>
#define c(x) cout<<x<<endl;
#define M 1000000007
using namespace std; 
#define int long long int
 
 
signed main()
{
    int n;
    cin>>n;
   int a[n],b[n];
   fp(i,0,n)
   cin>>a[i];
   
   fp(i,0,n)
   cin>>b[i];
   reverse(b,b+n);
   
   fp(i,0,n)
   {
       if(a[i]!=b[i])
       continue;
       
       bool ok = false;
       fp(j,0,n)
       {
           if(i==j)
           continue;
           
           if(a[i]!=b[j] && a[j]!=b[i])
           {
               swap(b[i],b[j]);
               ok = true;
               break;
           }
           
       }
       if(!ok)
       {
           cout<<"No"<<endl;
           return 0;
       }
   }
   cout<<"Yes"<<endl;
   fp(i,0,n)
   cout<<b[i]<<" ";
   
}
