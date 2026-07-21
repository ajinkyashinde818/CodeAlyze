#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long tab[30];
long long licz;
int f(char a)
{
    return int(a)-97;
}
void rek(int a,long long war)
{
    if(a==26)
    {
        licz=(licz+war)%mod;
        return;
    }
    rek(a+1,war);
    rek(a+1,(war*tab[a])%mod);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    string b;
    cin>>a>>b;
    int kon=0;
    for(int x=0;x<a;x++)
        tab[f(b[x])]++;
    rek(0,1);
    cout<<(licz-1+mod)%mod;
	return 0;
}
