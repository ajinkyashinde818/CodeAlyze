#include <cmath>
#include <iostream>
#include <functional>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <list>
#include <numeric>
using namespace std;

int main(){    
  int N,R;
  cin >> N >> R;
  if(N>=10){
    cout << R << endl;
  }else{
    cout << R+(100*(10-N))<< endl; 
  }
}
