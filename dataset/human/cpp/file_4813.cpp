#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;

    if(n < 10){
        cout << (100*(10 - n)) + k << endl;
    } else {
  
    cout << k << endl;
    }
  
    return 0;
}
