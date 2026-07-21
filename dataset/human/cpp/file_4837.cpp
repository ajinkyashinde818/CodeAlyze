#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

int main(){
    int N,R;

    cin >> N >> R;

    if(N < 10)cout << R + 100 * (10 - N) << endl;
    else cout << R << endl;

    return 0;
}
