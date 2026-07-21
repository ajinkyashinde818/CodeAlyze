#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;

int main(void){
	double t,d;
	cin>>t>>d;
	double ta,tb;
	cin>>ta>>tb;
	double da,db;
	cin>>da>>db;
	double min = 100000;
	
	for(int i = 0 ; i <= d ; i += da){
		for(int j = 0 ; j + i <= d ; j += db){
			if(min>abs(t-(ta*i+tb*j)/(i+j)))
				min=abs(t-(ta*i+tb*j)/(i+j));
		}
	}

	printf("%.10f\n",min);
	
}
