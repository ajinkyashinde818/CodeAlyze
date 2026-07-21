#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

bool kaibun(string s){
    size_t len = s.length();
    for(int i = 0; i < len/2; i++){
        if(s[i] != s[len-i-1]) return false;
    }
    return true;
}

int main(){
    int N,R=0;
    cin >> N >> R;
    if(N>9) cout << R << endl;
    else cout << R + 100*(10-N) << endl;
    return 0;
}
