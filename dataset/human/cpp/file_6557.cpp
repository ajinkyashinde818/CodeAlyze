#include <bits/stdc++.h>
using namespace std;

using fint64 = int_fast64_t;
template<fint64 MOD>
struct ModInt{
    fint64 x;
    ModInt():x(0){}
    ModInt(fint64 x):
        x(x>=0?x%MOD:(MOD-(-x)%MOD)%MOD)
        {}
    // 負号
    ModInt operator -() const{
        return ModInt(-x);
    }
    // 加算
    ModInt &operator +=(const ModInt &rhs){
        x+=rhs.x;
        if(x>=MOD) x-=MOD;
        return (*this);
    }
    ModInt operator +(const ModInt &rhs) const{
        return ModInt(*this)+=rhs;
    }
    // 減算
    ModInt &operator -=(const ModInt &rhs){
        x+=MOD-rhs.x;
        if(x>=MOD) x-=MOD;
        return (*this);
    }
    ModInt operator -(const ModInt &rhs) const{
        return ModInt(*this)-=rhs;
    }
    // 乗算
    ModInt &operator *=(const ModInt &rhs){
        x*=rhs.x;
        if(x>=MOD) x%=MOD;
        return (*this);
    }
    ModInt operator *(const ModInt &rhs) const{
        return ModInt(*this)*=rhs;
    }
    // 除算
    ModInt &operator /=(const ModInt &rhs){
        (*this)*=rhs.inverse();
        return (*this);
    }
    ModInt operator /(const ModInt &rhs) const{
        return ModInt(*this)/=rhs;
    }
    // 等号
    bool operator ==(const ModInt &rhs){
        return x==rhs.x;
    }
    bool operator !=(const ModInt &rhs){
        return x!=rhs.x;
    }
    // 累乗
    ModInt pow(fint64 n) const{
        fint64 tmp=x;
        fint64 ret=1;
        while(n>0){
            if(n&1) ret=ret*tmp%MOD;
            tmp=tmp*tmp%MOD;
            n>>=1ll;
        }
        return ModInt(ret);
    }
    // 逆元
    ModInt inverse() const{
        fint64 a=x,b=MOD,s=1,t=0;
        while(b>0){
            fint64 u=a/b;
            a-=u*b;
            s-=u*t;
            swap(a,b);
            swap(s,t);
        }
        return ModInt(s);
    }
    // 入出力
    friend istream &operator >>(istream &lhs,ModInt<MOD> &rhs){
        fint64 x; lhs>>x;
        rhs=ModInt<MOD>(x);
        return lhs;
    }
    friend ostream &operator <<(ostream &lhs,const ModInt<MOD> &rhs){
        return lhs<<rhs.x;
    }
};

int main() {
	const int MOD = 1e9 + 7;
	using mint = ModInt<MOD>;
	int n; cin >> n;
	string s; cin >> s;
	const int N = 2 * n;
	for(int i = 0; i < N; ++i) {
		if(not (i & 1)) s[i] = (s[i] == 'W' ? 'B' : 'W');
	}
	mint l = 0, ans = 1;
	for(int i = 0; i < N; ++i) {
		if(s[i] == 'W') l += 1;
		if(s[i] == 'B') {
			ans *= l;
			l -= 1;
		}
	}
	if(l != 0) ans = 0;
	for(int i = 2; i <= n; ++i) {
		ans *= i;
	}
	cout << ans << '\n';
	return 0;
}
