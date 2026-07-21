#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<bitset>
#include<utility>
#include<sstream>
#include<iomanip>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>

using namespace std;
typedef long long ll;
#define MP make_pair

int main(void) {
    int n,r;

    cin>>n>>r;

    if(n>=10)cout<<r<<"\n";
    else cout<<r+100*(10-n)<<"\n";
    
    
    return 0;
}
