#include<bits/stdc++.h>

using namespace std;


int main(void){
int n;
int arr[100001];
cin >> n;
for(int i=1;i<=n;i++)
    cin >> arr[i];
int cnt=0;
for(int i=1;i<=n;i++)
    if(arr[i]<=0)cnt++;
long long sum=0;
for(int i=1;i<=n;i++)
    sum+=abs((long long)arr[i]);
if(cnt%2==0){
    cout << sum;
}
else{
    int mi=2000000000;
    for(int i=1;i<=n;i++)
        mi=min(mi,abs(arr[i]));
    cout << sum-mi*2;
}
}
