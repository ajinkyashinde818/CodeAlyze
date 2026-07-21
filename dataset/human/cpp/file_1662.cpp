#include <bits/stdc++.h>
    using namespace std;
     
    int n;
    vector<int> r[1000];
     
    int main(){
    	scanf("%d", &n);
      	for(int i=1; i<1000; i++){
        	if(2*n == i*(i-1)){
            	puts("Yes");
              	for(int j=1, c=1; j<=i; j++){
                	for(int k=j+1; k<=i; k++, c++){
                      	r[j].push_back(c);
                      	r[k].push_back(c);
                    }
                }
              	printf("%d\n", i);
              	for(int j=1; j<=i; j++){
                	printf("%d ", i-1);
                    for(int k:r[j]) printf("%d ", k);
                  	puts("");
                }
                return 0;
            }
        }
      	puts("No");
    }
