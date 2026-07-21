#include <bits/stdc++.h>
using namespace std;

int main(void){

    int r,g,b,n;
    cin >> r >> g >> b >> n;
    
    long long result = 0;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            long long temp_b = n-(i*r+j*g);
            if(temp_b%b==0 && temp_b >= 0 && temp_b/b<=n-i-j) {
//                cout << i << " " << j << " " << temp_b/b << endl;
                result++;
            }
        }
    }

    cout << result << endl;

    return 0;
}
