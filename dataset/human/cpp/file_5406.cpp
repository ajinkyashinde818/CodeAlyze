#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <numeric>
using namespace std;
typedef long long ll;

int main(){
    int n,r;cin>>n>>r;
    if(n<10)r+=100*(10-n);
    cout<<r;
}
