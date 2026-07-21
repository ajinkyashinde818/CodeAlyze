#include <bits/stdc++.h>
using namespace std;
using ll = long long;





int main(){
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int count = 0;
    for (int r = 0; r <= 3000; r++)
    {
        for (int g = 0; g <= 3000; g++)
        {
            int v = N - R * r - G * g;
            if ( v >= 0 and v % B == 0) count++;
        }
        
    }
    cout << count << endl;
    
}
