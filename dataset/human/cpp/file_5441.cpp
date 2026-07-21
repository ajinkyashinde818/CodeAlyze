#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

int main(){
    using namespace std;

    int N, R;
    cin >> N >> R;
    if(N >= 10){
        cout << R << endl;
    }else{
        cout << 100*(10-N)+R << endl;
    }
    return 0;
}
