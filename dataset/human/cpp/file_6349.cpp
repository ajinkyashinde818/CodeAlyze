#include<bits/stdc++.h>
using namespace std;

long long n,ans,a,b=1;
string s;

long long P(long long a,long long b){
    for(long long i=2;i<=b;i++){
        a*=i;
        a%=1000000007;
    }
    return a;
} 

int main(){
    cin>>n>>s;
    for(long long i=0;i<2*n;i++){
        if(s[i]=='W'){
            if(a%2==1){
                a++;
            }
            else{
                b*=a;
                b%=1000000007;
                a--;
                if(a<0){
                    cout<<0<<endl;
                    return 0;
                }
            }
        }
        else{
            if(a%2==0){
                a++;
            }
            else{
                b*=a;
                b%=1000000007;
                a--;
                if(a<0){
                    cout<<0<<endl;
                    return 0;
                }
            }
        }
    }
    if(a){
        cout<<0<<endl;
        return 0;
    }
    cout<<P(b,n)<<endl;
}
