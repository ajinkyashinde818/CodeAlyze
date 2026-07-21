#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main (void){
	int n,i,a,j,flag,s[100001],t[100001],d[100001],value;
	cin >> n;
	flag=0;
	for(i=2;i<=1000;i++){
		if(i*(i-1)==2*n) {
			flag=1;
			a=i;
			break;
		}
	}
	if(flag==0){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	cout << a << endl;
	s[1]=1;
	t[1]=2;
	for(i=2;i<=n;i++){
		if(t[i-1]!=a){
			s[i]=s[i-1];
			t[i]=t[i-1]+1;
		} else {
			s[i]=s[i-1]+1;
			t[i]=s[i]+1;
		}
	}
	for(i=1;i<=a;i++){
		cout << a-1;
		value=1;
		for(j=1;j<=n;j++){
			if(s[j]==i||t[j]==i){
				d[value]=j;
				value++;
			}
		}
		for(j=1;j<=a-1;j++){
			cout << " " << d[j];
		}
		cout << endl;
	}
	return 0;
}
