#include <iostream>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include <algorithm>
#include <cstring>
#include<queue>
#include <stack>
#include<map>
#include<vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define ll long long
#define inf 999999999

int main(){
    ll n;
    ll r;
    cin>>n>>r;
    ll x;
    if(n>=10){
        cout<<r<<endl;
    }else{
        x=r+100*(10-n);
        cout<<x<<endl;
    }
    
    return 0;
}
