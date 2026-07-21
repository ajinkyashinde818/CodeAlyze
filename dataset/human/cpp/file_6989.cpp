#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    vector<int> B(n);
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<n;i++)
        cin>>B[i];
    reverse(B.begin(),B.end());
    int left=0;
    int right=n-1;
    int ll=-1;
    int rr=n;
    int lb=-1;
    int rb=n;
    for(int i=0;i<n;i++)
    {
        if(A[i]==B[i])
        {
            rr=i;
            if(ll==-1)
                ll=i;
        }
    }
    lb=ll;
    rb=rr;
    while(lb<=rb&&(left<ll||right>rr))
    {
        //cout<<"Hel0"<<endl;
        if(left<ll)
        {
            if(A[left]!=B[lb]&&A[lb]!=B[left])
            {
                swap(B[lb],B[left]);
                lb++;
            }
            left++;
        }
        if(right>rr)
        {
            if(A[right]!=B[rb]&&A[rb]!=B[right])
            {
                swap(B[rb],B[right]);
                rb--;
            }
            right--;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(A[i]==B[i])
        {
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
    for(auto const&e:B)
        cout<<e<<" ";
    cout<<"\n";
    return 0;
}
