#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int a,b,c,d,cnt=0;
	cin >> a >> b >> c >> d;
	
	
	for(int i=0;i<3001;i++){
		
		for(int j=0;j<3001;j++){
			
			if(d-(a*i+b*j) >=0 && (d-(a*i + b*j))%c == 0) cnt++;
			
			if((a*i + b*j) >= d)break;
		}
	}
	
	
	cout << cnt << endl;
	
	
	return 0;
}
