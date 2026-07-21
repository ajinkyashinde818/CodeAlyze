#include <bits/stdc++.h>
using namespace std;

int main() { 	
 	int R,G,B,N;
  cin >> R>>G>>B>>N;
	int r=R;
  int g=G;
  int b=B;
  int count =0;
  if(R==G==B){
  if(N%G==0){
      	int xxx=N/R; 
      int yyy=xxx+2;
      int yyyy=xxx+1;
        int yyyyy =yyy*yyyy;
    count=yyyyy/2;
}else{
    count =0;
    }
  }else{
  for(int i=0;i<=N;i+=r){
  	for(int x=0;x+i<=N;x+=g){
    	for(int y=0;y+x+i<=N;y+=b){
          if(y+x+i==N){
          count+=1;
          }
        }
    }
 	}
}
  cout << count << endl;
}
