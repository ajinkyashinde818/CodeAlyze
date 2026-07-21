#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

namespace Mylib{
    using namespace std;
}

int main(void){
    using namespace std;
    int N,R;
    
    cin >> N >> R;
    
    if(N>=10){
        cout << R << endl;
    }else{
        cout << R+100*(10-N) << endl;
    }
    return 0;
}
