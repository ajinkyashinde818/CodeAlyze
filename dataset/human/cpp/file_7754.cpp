#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	int N;
	cin>>N;
    vector <long>a(N);
    for(int i=0 ; i<N ; i++){
        cin>>a[i];
    }
	
	long x=0,y=0;
	long sum;
	long min;
	for(int i=1 ; i<N ; i++){
		y+=a[i];
	}
	x+=a[0];
	min=x-y;
	if(min<0)min*=-1;
	for(int i=1 ; i<N-1 ; i++){
		x+=a[i];
		y-=a[i];
		sum=x-y;
		if(sum<0)sum*=-1;
		if(min>sum)min=sum;
	}
	cout<<min<<"\n";
	
	
	return 0;
}
