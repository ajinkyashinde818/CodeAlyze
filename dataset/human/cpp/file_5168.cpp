#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(void){
  long int N,R;
  cin >> N >> R;
  
  long int W;
  if(N<10) W=R+100*(10-N);
  else W=R;
  
  cout << W << endl;
  
  long int sum=0;
  
	return 0; 
}
