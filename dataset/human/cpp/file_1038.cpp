#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[3],n;
    cin>>a[0]>>a[1]>>a[2]>>n;
    sort(a,a+3);

    int count=0;
    for (int i = 0; a[2]*i<=n; ++i) {
        for (int j = 0; a[1]*j <=n-a[2]*i ; ++j) {
            int z=n-a[2]*i-a[1]*j;
            if(z%a[0]==0)
                count++;
        }
    }
     cout<<count;
}
