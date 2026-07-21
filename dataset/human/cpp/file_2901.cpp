#include <iostream>
using namespace std;
int main(){
	
	long n;
  	cin >> n;
  	long a[n];
  	for(int i=0; i<n; i++){
    	cin >> a[i]; 
    }
  	
 	int cnt = 0; //マイナスの値の数
    long sum = 0;
  	for(int i=0; i<n; i++){
    	if(a[i] < 0){
         	cnt ++;
          	a[i] *= -1;
        }
    }
  
    long min = 1000000000;
  	for(int i=0; i<n; i++){
      if(a[i] < min){
       	min = a[i]; 
      }
    }
  
  	for(int i=0; i<n; i++){
     	sum += a[i];
    }
  	
  	if(cnt % 2 == 1){
     	 sum -= min * 2;
    }
  
  
  	cout << sum  << endl;
  
}
