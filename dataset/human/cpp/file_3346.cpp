#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int min,cnt=0;
    for(int i=0;i<n;++i){
        cin >> a[i];
        if(a[i]<0){
            a[i]*=-1;
            ++cnt;
        }
        if(i==0) min=a[i];
        if(min>a[i]) min=a[i];
    }
    long int sum=0;
    for(int i=0;i<n;++i) sum += a[i];
    if(cnt%2==1) sum -= min*2;
    cout << sum << endl;
    return 0;
}
