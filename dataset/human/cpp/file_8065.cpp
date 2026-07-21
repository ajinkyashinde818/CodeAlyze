#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long a[200000];
    long long sum=0;
    long long ans=9223372036854775807;
    for(int i=0;i<n;i++){
        int b=0;
        cin >> b;
        if(i!=0)a[i]=b+a[i-1];
        if(i==0)a[i]=b;
    }
    sum=a[n-1];
    for(int i=0;i<n-1;i++){
        ans=min(abs(sum-a[i]*2),ans);
    }

    cout << ans << endl;
    return 0;
}
