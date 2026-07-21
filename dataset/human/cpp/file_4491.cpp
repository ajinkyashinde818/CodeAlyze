#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstring>

typedef long long ll;
using namespace std;

#define mod 1000000007
#define INF 1000000000 //(int)1e9
#define LLINF 8000000000000000000 //(ll)2e18
#define PI  3.1415926536

#define SIZE 100000

int main(){
    int a,b;
    
    scanf("%d%d",&a,&b);
    
    for(int i=0;i<a/2+1;i++){
        printf(i!=a-1?"%d ":"%d\n",0);
    }
    
    for(int i=a/2+1;i<a;i++){
        printf(i!=a-1?"%d ":"%d\n",b);
    }
}
