#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int>arr(n), brr(n);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> brr[i];
    }
    reverse(brr.begin(),brr.end());
    int number = -1;
    for(int i=0; i<n; i++)
    {
        if(arr[i] == brr[i])
        {
            number = arr[i];
            break;
        }
    }
    int leftPos = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==number && brr[i]==number)
        {
            leftPos = i;
            break;
        }
    }
    int rightPos = -1;
    for(int i=n-1; i>=0; i--)
    {
        if(arr[i]==number && brr[i]==number)
        {
            rightPos = i;
            break;
        }
    }
    for(int i=0; i<n && number!=-1; i++)
    {
        if(arr[i]!=number && brr[i]!=number && leftPos<=rightPos)
        {
            swap(brr[i],brr[leftPos]);
            leftPos++;
        }
    }
    if(leftPos<=rightPos)
    {
        cout << "No\n";
    } else
    {
        cout <<"Yes\n";
        for(int x : brr)cout << x << " ";
        cout << endl;
    }
}
