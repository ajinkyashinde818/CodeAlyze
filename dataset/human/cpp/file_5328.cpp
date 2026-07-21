#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <unordered_set>
using namespace std;

int main(void){
    int N, R;
    cin >> N >> R;
    if(N >= 10){
        cout << R << endl;
    }else{
        cout << R+100*(10-N) << endl;
    }
    return 0;
}
