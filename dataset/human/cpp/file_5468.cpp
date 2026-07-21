#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	if(n<=10){
		cout<<m+100*(10-n);
	}
	else
		cout<<m;
	return 0;
}
