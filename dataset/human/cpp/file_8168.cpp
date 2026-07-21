#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long>a(n);
    long sum = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    unsigned long min= -1;
    for(int i = 0; i<n-1; i++){
        if(i>0)
            a[i] += a[i-1];
        long sunu = a[i];
        long arai = sum-a[i];
        long dis = abs(sunu-arai);
        if(dis<min)
            min = dis;
    }
    cout<<min;
}
