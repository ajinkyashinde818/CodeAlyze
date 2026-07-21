#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll N; cin >> N;
    string S; cin >> S;
    ll mod = 1000000007;
    map<char,ll> alp;
    for(char s = 'a'; s <= 'z'; s++)
    {
        for(ll i = 0; i < N; i++)
        {
            if(S.at(i) == s)
            {
                alp[s] += 1; //Sにおける文字毎の出現回数
            }
        }
    }
    vector<ll> sum(26);
    for(char s = 'a'; s <= 'z'; s++)
    {
        ll A = alp[s]; //例えばs=aならa(b+1)(c+1)...を求めていく
        for(char t = s + 1; t <= 'z'; t++)
        {
            A = (A*(alp[t] + 1)) % mod;
        }
        sum.at(s-97) = A; //sの出現回数とsから後の各文字の（出現回数+1）を掛け合わせたもの
    }
    ll ans = 0;
    for(int i = 0; i < 26; i++)
    {
        ans += sum.at(i); //上のsumの総和が条件を見たす部分列の個数になる
    }
    cout << ans % mod << endl;
}
