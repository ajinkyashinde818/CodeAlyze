#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

struct vertex{
    int X;
    int Y;
};

int	gcd(int	a, int b){
    while( b ){
        int	m = a % b;
        a = b;
        b = m;
    }
    return a;
}

int	lcm(int a, int	b){
    return (a*b)/gcd(a,b);
}

int isPrim(int a){
    if(a==1){
        return 0;
    }
    for(int i=2;i<=(a+1)/2;i++){
        if(a%i==0){
            return 0;
        }
    }
    return 1;
}

int main(int argc, const char * argv[])
{
    //std::ios::sync_with_stdio(false);
    //scanf("%s",S);
    //scanf("%d",&N);
    //getline(cin, target);
    //cin >> x >> y;
    //????????????

    int n,m;
    cin >> n >> m;
    
    if(n==1){
        cout << m << endl;
        return 0;
    }
    if(n==2){
        cout << "0 0"  << endl;
        return 0;
    }

    if(n%2==0){
        for(int i=1;i<=n/2+1;i++){
            cout << 0 << " ";
        }
        for(int i=n/2+2;i<n;i++){
            cout << m << " ";
        }
        cout << m << endl;
        return 0;
    }
    if(n%2==1){
        for(int i=1;i<=(n+1)/2;i++){
            cout << 0 << " ";
        }
        for(int i=(n+1)/2+1;i<n;i++){
            cout << m << " ";
        }
        cout << m << endl;
        return 0;
    }
    

    
    //???????????§
    //cout << "ans" << endl;????????????
    //printf("%.7f",p);
    //printf("%f\n",pow(2,ans.size()));
    
    return 0;
}
