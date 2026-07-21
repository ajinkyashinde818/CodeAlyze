#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include<string>
#include <stack>
#include<queue>
#include<map>
#include <stdlib.h>

using namespace std;

int main() {

	int r,g,b,n,cnt=0;
	cin>>r>>g>>b>>n;
	for(int i=0;i<3001;i++){
		for(int j=0;j<3001;j++){
			if(r*i+g*j+abs(b*((n-r*i-g*j)/b))==n)cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
