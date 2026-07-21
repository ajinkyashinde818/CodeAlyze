#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int sum=0;
    int N,R,ans;
    cin >> N >> R;

    if(N<10){
        ans = R +100*(10-N);
        cout << ans;
    }else{
        cout << R;
    }

    return 0;
    
  
}
