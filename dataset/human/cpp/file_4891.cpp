#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(void){
    
    int N, R;
    cin >> N >> R;
    
    if(N >= 10){
        cout << R << endl;
    }
    else{
        cout << R + (100 *(10 - N)) << endl;
    }

}
