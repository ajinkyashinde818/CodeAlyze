#include<bits/stdc++.h>
using namespace std;

int main() {
	int N,M;
  	cin >> N >> M;
  
  	vector<string> a(N),b(M);
  
  	for(int i = 0; i < N; i++) {
    	cin >> a.at(i);
    }
  
  	for(int i = 0; i < M; i++) {
    	cin >> b.at(i);
    }
  
  	int l =0,times = N - M + 1;
  	string ans = "No";
  
  	while(l < times) {
    	int h = 0;
      	bool stop = false;
      while(h < times) {
        bool can = true;
        for(int i = l; i < l + M; i++) {
        	for(int j = h; j < h + M; j++) {
            	if(a.at(i).at(j) != b.at(i - l).at(j - h)) {
                	can = false;
                }
            }
        }
          
        if(can)  {
          	ans = "Yes";
            stop = true;
          	break;
          }        	
      h++;
      }     
      if(stop) break;     
      	l++;
    }
  	cout << ans << endl;
}
