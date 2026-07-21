#include <bits/stdc++.h>
using namespace std;

int n,innerRating,displayedRating;

int main(){
	cin>>n>>displayedRating;
	if(n >= 10){
		innerRating = displayedRating;
	}else{
		innerRating = displayedRating + 100 * (10 - n);
	}
	cout<<innerRating<<endl;
}
