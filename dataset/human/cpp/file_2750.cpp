#include <bits/stdc++.h>
using namespace std;
int main(void){
	int n,i,neganum,min,j;
  	long result;
  	cin >> n;
  	int m[n];
  	neganum = 0;
  	result = 0;
  	for (i=0;i<n;i++){
    	cin >> m[i];
      	if (m[i]<=0){
        	neganum += 1;
        }
    }
  	if (neganum%2 == 0){
    	for (i=0;i<n;i++){
        	result += abs(m[i]);
        }
    printf("%ld",result);
    return 0;
    }else{
      	min = 100000;
    	for (i=0;i<n;i++){
          	if (abs(m[i])<=min){
            	min = abs(m[i]);
                j = i;
            }
          	m[i] = abs(m[i]);
        }
    	for (i=0;i<n;i++){
          	if (i == j){
            	result -= m[i];
            }else{
            	result += m[i];
            }
        }
    printf("%ld",result);
    return 0;
    }
}
