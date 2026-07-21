#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long int LL;
LL su[100005][2];
LL d[100005][2][2];
int main(){
	LL a,b,c;
	LL ff[5]={0};
	LL x,y;
	int i,j,k;
	LL n,t;
	LL s=0;
	cin>>n>>t;
	for(i=0;i<n;i++){
		cin>>su[i][0]>>su[i][1];
	}
	a=0,b=0,c=0;
	for(i=0;i<n;i++){
		c+=su[i][1];
		b=c-su[i][0];
		d[i+1][0][0]=d[i][0][0]>b?d[i][0][0]:b;
		b=c-su[i][0]*2;
		d[i+1][0][1]=d[i][0][1]>b?d[i][0][1]:b;
	}
	a=0,b=0,c=0;
	for(i=n-1;i>=0;i--){
		c+=su[i][1];
		b=c-(t-su[i][0]);
		d[i][1][0]=d[i+1][1][0]>b?d[i+1][1][0]:b;
		b=c-(t-su[i][0])*2;
		d[i][1][1]=d[i+1][1][1]>b?d[i+1][1][1]:b;
	}
	for(i=0;i<=n;i++){
		//printf("%d %d %d %d\n",d[i][0][0],d[i][0][1],d[i][1][0],d[i][1][1]);
		a=d[i][0][0]+d[i][1][1];
		if(s<a)s=a;
		a=d[i][0][1]+d[i][1][0];
		if(s<a)s=a;
	}
	cout<<s<<endl;
	return 0;
}
