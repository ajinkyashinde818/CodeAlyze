#include<bits/stdc++.h>
using namespace std;

int main(){
    int r, g, b, n; 
    vector<int> input(3);
    cin >> input[0] >> input[1] >> input[2] >> n;
    sort(input.begin(), input.end());
    r = input[2]; g = input[1]; b = input[0];
    int ans =0;
    
    int r_n = n/r; 
    int g_n = n/g; 
    int b_n = n/b;

    for(int i=0; i<=r_n; i++){
        for(int j=0; j<=g_n; j++){
            if( (n-r*i-g*j)%b==0 && (n-r*i-g*j)/b >=0)
                ans++ ;
        }
    }
    cout << ans << endl;
    return 0;
}
