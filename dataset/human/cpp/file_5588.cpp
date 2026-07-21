#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
int main(){
	int n,r;
	cin>>n>>r;
	if(n>10)cout<<r;
	else cout<<r+100*(10-n); 
}
