#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    int flag=0;
    long long int MIN=1e9;
    long long int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]<0){
            a[i]*=-1;
            flag++;
        }
        MIN=min(MIN,a[i]);
        ans+=a[i];
    }
    if(flag%2==1)ans-=(MIN*2);
    cout << ans << endl;
}
