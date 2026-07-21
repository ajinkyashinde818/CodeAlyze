#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
long long int a,b[100010],c[100010],ans =0,ant=0;

cin >> a ;

for(int i=0;i<a;i++)
cin >> b[i];

for(int i=0;i<a;i++){
c[i] = abs(b[i]);
ans += c[i];
}

for(int i=0;i<a;i++){
 
 if(b[i]<0){
    ant ++;
    }
    
    }
    sort(c,c+a);
    
    if(ant %2 == 0){
    
    cout << ans << endl;
    }
    
    else{
    
    cout << ans - 2*c[0] << endl;
    }
    
    }
