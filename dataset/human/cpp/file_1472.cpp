#include<bits/stdc++.h>
using namespace std;
namespace whatever{
	int readu(){
		char ch=getchar();
		while(!isdigit(ch))
			ch=getchar();
		int value=ch-'0';
		ch=getchar();
		while(isdigit(ch)){
			value=value*10+ch-'0';
			ch=getchar();
		}
		return value;
	}
	void writeu(int n){
		if(n<10)
			putchar(n+'0');
		else{
			writeu(n/10);
			putchar(n%10+'0');
		}
	}
	void run(){
		cerr<<"time(0): "<<time(0)<<endl;
		int n=readu();
		int i=0;
		for(int sum=0; true; ++i, sum+=i)
			if(sum>n){
				puts("No");
				return;
			}
			else if(sum==n)
				break;
		puts("Yes");
		writeu(i+1);
		putchar('\n');
		vector<vector<int> > result(i+1);
		int index=0;
		for(int j=0; j<=i; ++j){
			for(int k=0; k<j; ++k)
				result.at(j).push_back(index+k);
			for(int k=0; k<j; ++k)
				result.at(k).push_back(index+k);
			index+=j;
		}
		for(int j=0; j<=i; ++j){
			writeu(result.at(j).size());
			putchar(' ');
			for(int value: result.at(j)){
				writeu(value+1);
				putchar(' ');
			}
			putchar('\n');
		}
	}
}
int main(){
	whatever::run();
}
