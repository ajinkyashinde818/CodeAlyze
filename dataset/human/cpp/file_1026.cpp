#include<bits/stdc++.h>
using namespace std;

int main(){
    int r,g,b,n;
    cin>>r>>g>>b>>n;
    int tot=0;
    for(int i=0;i<=(n);i++){
	for(int j=0;j<=(n);j++){
	    int k = (n-(i*r+j*g));
	    if(k%b==0){
	    	if(k/b>=0)
		    ++tot;
	    }
	}
    }
    cout<<tot<<endl;
}
