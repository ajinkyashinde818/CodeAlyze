#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main(){
 	int n;
 	cin>>n;
    for(int i=0;i<n;i++){
 	    cin>>a[i];
 	}
 	
 	sort(a, a+n);
 	for(int i=0;i<n-1;i++){
 	    if(a[i]+a[i+1]<0){
 	        a[i]*=(-1);
 	        a[i+1]*=(-1);
 	        i++;
 	    } else break;
 	}
 	
 	cout<<accumulate(a, a+n, 0LL)<<endl;
 }
