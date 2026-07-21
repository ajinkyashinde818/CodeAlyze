#include <bits/stdc++.h>
#include<math.h>
#include<queue>
#include<cstdio>
#include<set>
#include<map>
using namespace std;

int main(){
    int N,R;
    cin >> N >> R;
    int a;
    if (N>= 10) a=R;
    else a=R+(100*(10-N));
    cout << a << endl;
    return 0;
}
