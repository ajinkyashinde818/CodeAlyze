#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[3], n, count=0;
    cin >> a[0] >> a[1] >> a[2] >> n;
    sort(a, a+3);
    for(int i=n/a[2];i>=0;i--){
        int N = n;
        N -= a[2] * i;
        for(int j=N/a[1];j>=0;j--){
            if((N-(a[1] * j))%a[0]==0){
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
