#include <iostream>
#include <vector>
#include <algorithm>
typedef long long LL;

using namespace std;
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    LL a[n];
    LL sum=0;
    for(int i=0;i<n;i++){
        int b;
        cin >> b;
        sum += b;
        a[i] = 2*b;
    }
    sum -= a[0];
    LL min=abs(sum);
    for(int i=1;i<n-1;i++){
        sum-=a[i];
        if(min>abs(sum)) min=abs(sum);
    }
    cout << min << endl;
    return 0;
}
