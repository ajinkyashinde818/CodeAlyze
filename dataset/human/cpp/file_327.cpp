#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;
  int count = 0;
  
  cin >>a>> b>>c>> d;
  
  for(int r=0; r <= d; r++)
  {
    for(int g=0; g <= d; g++)
	{
      if(d - r * a - g * b < 0)
        continue;
      if((d - r * a - g * b) % c == 0){
        count++;
        continue;
      }
    }
  }

  cout << count << endl;

}
