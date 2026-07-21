#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include<numeric>
#include<cctype>
#include<random>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++) //0から
#define REP(i,n) for(int j=i;j<n;j++) //iから
#define in(a) cin>>a
#define out(a) cout<<a<<endl

long long int kaijo(long long int n){
    if(n == 0) return 1;
    return n * kaijo(n-1);
}


vector<bool> is_prime;
void Eratosthenes(long long int n){
    is_prime.resize(n+1,true);
    is_prime[0]=false;
    is_prime[1]=false;
    for(long long int i = 2; i <= n; i++){
        if(is_prime[i]){
            for(long long int j = i*i; j <= n; j++){
                is_prime[j] = false;
            }
        }
    }
}

//素数列挙
vector<long long int> Prime;
void Prime_Enumeration(long long int n){
    Eratosthenes(n);
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            Prime.push_back(i);
        }
    }
}

long long int gcd(long long int a, long long int b){
    if(a<b){
        swap(a,b);
    }
    long long int r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return r;
}

long long int lcm(long long int a, long long int b){
    long long int g = gcd(a,b);
    long long int l = (a * b) / g;

    return l;
}

//aが負の時でも余りを非負にしたいとき
long long  mod(long long a, long long m){
    return (a % m + m) % m;
}

//拡張ユークリッド ap + bq = gcd(a,b)
long long extGCD(long long a, long long b, long long &p, long long &q){
    if(b == 0){ p = 1; q = 0; return a;}
    long long d = extGCD(b, a % b, q, p);
    q -= a /b * p;
    
    return d;
}

//中国剰余定理
pair<long long, long long> ChineseRem(long long b1, long long m1, long long b2, long long m2){
    long long p, q;
    long long d = extGCD(m1, m2, p, q);

    if((b2-b1) % d != 0) return make_pair(0, -1); //解なし

    long long m = m1 * (m2 / d);
    long long tmp = (b2 - b1) / d * p % (m2 / d);
    long long r =mod(b1 + m1 * tmp, m);

    return make_pair(r, m);
}

//mod.mでのa^{-1}
long long modinv(long long a, long long m){
    long long b = m, u = 1, v = 0;
    while(b){
        long long t = a /b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if(u < 0)u += m;
    return u;

}
const long long MOD = 1000000007;

//key以上のうち最小の要素のindex
int binary_search(long long int *a, long long int n, long long int key){
    long long int right = n, left = -1;
    long long int md = (right + left) / 2;

    while(right - left > 1){
        if(a[md] <= key){
            right = md;
        }else{
            left = md;
        }
        md = (right + left) / 2;
    }
    if(left == -1) return -1; //無い場合
    return right;
}


int main(){
    long long int n,r;
    string s;

    cin>>n>>r;

    if(n>=10){
        cout<<r<<endl;
        return 0;
    }

    cout<< r + 100 * (10-n)<<endl;


    return 0;
}
