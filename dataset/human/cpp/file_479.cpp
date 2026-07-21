#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,n,m;
    int s=0;
    cin>>a>>b>>c>>n;
    for (int i = 0; a*i <= n; i++){
        for (int j = 0; a*i+b*j <= n; j++){
            int k = n-a*i-b*j;
            if (k%c == 0) s++;
        }
    }
    cout<<s<<endl;
}
