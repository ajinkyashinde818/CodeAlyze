//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,a[100005],b[100005],f[100005],cnt,ans,s[100005];
map<int,int> m;
bool ok=1;
int get(int x){return x==f[x]?x:f[x]=get(f[x]);}
int main(){
    scanf("%d",&n);
    ++n;
    for(int i=1;i<n;++i)scanf("%d",a+i),a[n]^=a[i];
    for(int i=1;i<n;++i)scanf("%d",b+i),b[n]^=b[i];
    for(int i=1;i<=n;++i)++m[a[i]];
    for(int i=1;i<=n;++i){
        --m[b[i]];
        if(m[b[i]]<0)ok=0;
    }
    if(!ok){
        puts("-1");
        return 0;
    }
    for(int i=1;i<=n;++i)if(a[i]!=b[i])ok=0;
    if(ok){
        puts("0");
        return 0;
    }
    for(int i=1;i<=n;++i){
        if(m[a[i]])a[i]=m[a[i]];
        else a[i]=m[a[i]]=++cnt;
    }
    for(int i=1;i<=n;++i)b[i]=m[b[i]];
    for(int i=1;i<=cnt;++i)f[i]=i;
    for(int i=1;i<=n;++i){
        if(a[i]==b[i]) continue;
        ++ans;
        if(get(a[i])!=get(b[i]))f[f[a[i]]]=b[i];
    }
    for(int i=1;i<=n;++i)if(a[i]!=b[i])++s[get(a[i])];
    for(int i=1;i<=cnt;++i)if(get(i)==i&&s[i]>1)++ans;
    if(a[n]!=b[n])--ans;
    if(s[get(a[n])]>1)--ans;
    printf("%d\n",ans);
    //system("pause");
    return 0;
}
