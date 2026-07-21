#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <list>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip> // setprecisionを使用するのに必要 cout << fixed << setprecision(15) << p でpを小数点以下15桁表示
using namespace std;
#define REPD(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) REPD(i, 0, n)
typedef long long ll;
#define fin(ans) cout << (ans) << '\n'
/*

*/
int main()
{
    int N;
    cin >> N;
    ll a[N];
    ll sums = 0,suma = 0;
    ll ans = 100000000000000000;
    REP(i,N){
        cin >> a[i];
        suma += a[i];
    }
    //sumaが全部の輪。sumsに足しながら引いていく。最低でも1つ選ばなくてはならないのでそうする。
    sums += a[0];
    suma -= a[0];
    ans = min(ans,abs(sums-suma));

    REPD(i,1,N-1){
        sums += a[i];
        suma -= a[i];
        ans = min(ans,abs(sums-suma));
    }
    fin(ans);
    return 0;
}
