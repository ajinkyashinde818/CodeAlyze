#include<bits/stdc++.h>
using namespace std;

int main(){
    int r,g,b,n;
    cin>>r>>g>>b>>n;
    long long int counter = 0;
    for(int i=0;i<=(int)n/r;i++){
        for(int j=0;j<=(int)n/g;j++){
            if((n - r*i -g*j)%b==0 && (r*i + g*j)<=n){
                counter++;
            }
        }
    }
    cout<<counter<<endl;
}
