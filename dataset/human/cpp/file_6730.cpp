#include <bits/stdc++.h>

using namespace std;

template<typename T>
T gcd(T a,T b){
    if(b==0)return a;
    return gcd(b,a%b);
}

template<typename T>
T lcm(T a,T b){
    T d=gcd(a,b);
    return (a/d)*b;
}

long long mypow10(int n){
    long long ret=1;
    while(n>=1){
        --n;
        ret=ret*10;
    }
    return ret;
}

int main(){
    string s;
    cin>>s;
    long long a=0;
    long long b=0;
    long long c=0;
    int bbit=0;
    int cbit=0;
    bool rep=false;
    bool dot=false;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]=='.'){
            dot=true;
            continue;
        }
        if(!dot){
            a=a*10;
            a+=s[i]-'0';
        }
        else{
            if(s[i]=='('){
                ++i;
                rep=true;
                while(s[i]!=')'){
                    c=c*10;
                    c+=s[i]-'0';
                    ++i;
                    ++cbit;
                }
                break;
            }
            else{
                b=b*10;
                b+=s[i]-'0';
                ++bbit;
            }
        }
    }
    long long u,d;
    u=b;
    d=mypow10(bbit);

    long long comd;

    comd=gcd(u,d);
    u=u/comd;
    d=d/comd;

    if(rep){
        long long cu,cd;
        cu=c;
        cd=mypow10(bbit+cbit)-mypow10(bbit);

        comd=gcd(cu,cd);
        cu=cu/comd;cd=cd/comd;

        long long comm;
        comm=lcm(d,cd);

        u=u*(comm/d);
        u+=cu*(comm/cd);

        d=comm;

    }

    comd=gcd(u,d);
    u=u/comd;
    d=d/comd;

    u+=a*d;

    cout<<u<<"/"<<d<<endl;
    return 0;
}
