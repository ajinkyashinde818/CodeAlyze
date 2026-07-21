#include<bits/stdc++.h>
 
using namespace std;

int main(){
int n;
cin>>n;
long long  a[n]={0};
long long sum1=0,sum2=0;
long long t=0;
long long min=300000000000;
for(int i=1;i<=n;i++)  {
cin>>a[i];
sum1+=a[i];
}
for(int j=n;j>1;j--){
	sum1-=a[j];
	sum2+=a[j];
	 t=abs(sum1-sum2);
	 if(t<min)  min=t;
}
cout<<min;
}
