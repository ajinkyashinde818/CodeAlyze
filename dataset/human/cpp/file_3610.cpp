#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,neg=0;
    cin>>n;
    long long sum=0,mini=INT_MAX;
    vector<long long> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=abs(v[i]);
        if(v[i]<0) neg++;
        mini=min(mini,abs(v[i]));
    }
    if(neg%2==1){
        cout << sum-2*mini<<endl;
    }else {
        cout<<sum<<endl;
    }

    return 0;
}
