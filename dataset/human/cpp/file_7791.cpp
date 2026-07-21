#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    long N;
    long long sum=0;
    cin >> N;
    long long a[200001]={0};
    for(int i=0;i<N;i++){
        cin >> a[i];
        sum += a[i];
    }
    long long ans=10000000000;
    long long tmp=0;
    for(int k=0;k<N-1;k++){
            tmp+=a[k];
            ans=min(abs(sum-2*tmp),ans);
    }
    cout << ans << endl;
    return 0;
}
