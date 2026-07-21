#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <iomanip>
#include <iostream>
using namespace std;
 
int gcd(int x,int y){
    if(y==0)return x;

    return gcd(y,x%y);
}
int lcm(int x,int y){
    return x*y/gcd(x,y);
}

int main(){

    int R,G,B,N,ans=0;
    cin>>R>>G>>B>>N;
    
    for(int r=0;r<=N/R;r++){
        for(int g=0;g<=N/G;g++){
            int x=N-r*R-g*G;
            int b=x/B;
            if(x%B==0&&b>=0)ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}
