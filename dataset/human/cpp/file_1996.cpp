#include<algorithm>
#include<clocale>
#include<cmath>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<iostream>
#include<istream>
#include<map>
#include<math.h>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
long long n,a[100010],ans,num=1e10;
int main(){
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n-1;i++)
		if (a[i]<0){
			a[i]*=-1;
			a[i+1]*=-1;
		}
	for (int i=0;i<n;i++) ans+=a[i];
	if (a[n-1]<0){
		ans-=a[n-1]*2;
		a[n-1]*=-1;
		for (int i=0;i<n;i++) num=min(num,a[i]);
		cout<<ans-num*2<<endl;
	}
	else
		cout<<ans<<endl;
	return 0;
}
