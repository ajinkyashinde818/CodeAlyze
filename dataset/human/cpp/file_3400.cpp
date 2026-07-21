#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    bool zeroExist = false;
    vector <int> neg, s(n);
    long long ans=0;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        if(s[i] > 0) ans += s[i];
        else if(!s[i]) zeroExist = true;
        else{
            s[i] *= -1;
            neg.push_back(s[i]);
            ans += s[i];
        }
    }
    if((neg.size() % 2) && (!zeroExist)){
        sort(s.begin(), s.end());
        ans -= 2 * s[0];
    }
    cout << ans << endl;
    return 0;
}
