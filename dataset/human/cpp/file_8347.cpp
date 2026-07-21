#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <locale>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>
#include <complex.h>
#include <fenv.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n,m,i,j,k,f;
	cin>>n>>m;
	string a[n+1],b[m+1];
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<m;i++) cin>>b[i];
	for(i=0;i<n-m+1;i++)
	{
		for(j=0;j<n-m+1;j++)
		{
			bool ok=1;
			for(k=i;k<i+m;k++) for(f=j;f<j+m;f++) if(a[k][f]!=b[k-i][f-j]) ok=0;
			if(ok){
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}
