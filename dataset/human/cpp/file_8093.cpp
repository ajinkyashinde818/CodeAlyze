#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;
int main() {
    long long int n;
    cin >> n;
    long long int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    long long int sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i];

    long long int x,y,sum1=sum,sum2,min=INT_MAX;
    for(int i=1;i<n;i++){
        sum1-=a[n-i];
        sum2=sum-sum1;
        if(abs(sum2-sum1)<min)
            min=abs(sum2-sum1);
    }
    cout << min << endl;
    return 0;
}
