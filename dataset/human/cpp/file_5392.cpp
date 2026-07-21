#include <iostream>//cout<<right で右揃え
#include <iomanip>//cout<<stw(数字) で空白による桁揃え
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>//abs()で整数絶対値
#include <cmath>//abs()かfabs()で少数絶対値

using namespace std;

int main(void){
    int N,R,In;
    cin >> N >> R;
    if(N<10){
        In = R + 100*(10-N);
    }else{
        In = R;
    }
    cout << In << endl;
    return 0;
}
