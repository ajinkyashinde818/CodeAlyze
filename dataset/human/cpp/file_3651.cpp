#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n];
	int count=0;
	for(int i=0 ; i<n ; i++){
		cin >> a[i];
		if (a[i]<0) count++;
	}
	long long all=0;
	if (count%2==0){
		for (int i=0;i<n;i++){
			if (a[i]<0) a[i]=a[i]*-1;
			all+=a[i];
		}
		cout << all << endl;
	} else {
		int min=1000000000;
		for(int i=0;i<n;i++){
			if (a[i]<0) a[i]=a[i]*-1;
			if (a[i]<min) min=a[i];
			all+=a[i];
		}
		all=all-min*2;
		cout << all << endl;
	}
	return 0;
}
