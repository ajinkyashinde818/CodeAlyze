#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <set>
#include <iomanip>
#include <sstream>
using namespace std;
int main(void){
    int n, r;
    cin>>n>>r;
    int ans=r;
    if(n>=10) {cout<<r<<endl;}
    else{
        r-= -100*(10-n);
        cout<<r<<endl;
    }
}
