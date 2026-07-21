#include<iostream>
using namespace std;
int main()
{
	long long max= 1000000001;
	int N,fre=0;
	long long Sum=0,Min=max,tmp;
	
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> tmp;
		if(tmp<0){
			tmp=0-tmp;
			fre++;
		}
		Sum += tmp;
		if(tmp<Min) Min=tmp;
	}
	if(fre%2==1) Sum-=Min*2;

		cout << Sum;
	return 0;
}
