#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(void){
	int r,g,b,n,i,j,k,count,rr,g2,b2;
  	cin >> r >> g >> b >> n;
  	if(g>r){
    	swap(r,g);
    }
  	if(b>g){
    	swap(b,g);
    }
  	count = 0;
  	g2 = g;
  	b2 = b;
  	rr = g2 % b2;
  	while(rr!=0){
      g2 = b2;
      b2 = rr;
      rr = g2 % b2;
  	}
  	for(i=0;r*i<=n;i++){
           if(n< r*i){
                break; 
           }else if(n== r*i){
                count += 1;
                break;
           }
      		if((n-r*i)%b2!=0){
            	continue;
            }
            for(j=0;r*i+g*j<=n;j++){
                if(n== r*i+g*j){
                	count += 1;
                    break;
                }else if((n- (r*i+g*j))%b==0){
                	count += 1;
                }
          	}
    }
  	cout << count;
  	return 0;
}
