#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <math.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <long> vec(n);
    int count = 0;
    for(int i=0;i<n;i++){
        long a;
        cin >> a;
        if(a<0) count++;
        vec.at(i)=abs(a);
    }
    count %=2;
    sort(vec.begin(),vec.end(),greater<long>());
    
    int s,t;
    if (count ==0){
        s=n;
        t=n-1;
    }
    else{
        s=n-1;
        t=n-2;
    }
    
    long tasu=0;
    
    for (int i=0;i<s;i++){
        tasu+=vec.at(i);
    }
    
    long hiku=0;
    for (int i=n-1;i>t;i--){
        hiku+=vec.at(i);
    }
    
    long ans=tasu-hiku;
    
    cout << ans << endl;
    
}
