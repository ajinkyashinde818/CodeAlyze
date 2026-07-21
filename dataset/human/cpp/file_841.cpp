#include<iostream>
using namespace std;

int main(void){

	int R,G,B,N;
	cin >> R >> G >> B >> N;
	int r=0,g=0,b=0;
	int count=0;

	int maxr,maxg;
	maxr=N/R;

	for(r=maxr;r>=0;r--){
		maxg=(N-(R*r))/G;
		for(g=maxg;g>=0;g--){
			b=(N-((R*r)+(G*g)))%B;
			if(b==0)
				count++;
		}
	}

	cout << count << endl;

	return 0;
}
