#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int join_count=0;
  int outside_rate;
  int inside_rate;
  cin >> join_count >> outside_rate;


  if(10 <=  join_count){
	inside_rate = outside_rate;
  }
  else{
	//outside_rate = inside_rate - 100 * (10 - join_count);
	inside_rate = outside_rate + 100 * (10 - join_count);
  }
  cout << inside_rate << endl;
  return 0;
}
