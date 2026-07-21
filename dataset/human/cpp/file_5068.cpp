#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int ll;
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,r; cin >> n >> r;
    if(n>=10){
        cout << r << endl;
    }else{
        cout << r+100*(10-n) << endl;
    }
}
