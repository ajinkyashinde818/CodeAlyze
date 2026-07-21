#include <stdio.h>
#include <math.h>
#define swap(a,b) a^=b^=a^=b

	int ans = 8;
	int A[31] = {0} ;
	int B[] = {0,1,1,1,1,1,1,1,1,1,2,2,2,4,4,4,6,6,6,5,5,5,3,3,3,3,3,3,3,3,3} ;

	void a(){
    	swap(A[1],A[24]);
    	swap(A[4],A[27]);
    	swap(A[7],A[30]);
    	swap(A[10],A[21]);
    	swap(A[16],A[18]);
    return;
	}
 
	void b(){
    	swap(A[3],A[22]);
    	swap(A[6],A[25]);
    	swap(A[9],A[28]);
    	swap(A[12],A[19]);
    	swap(A[13],A[15]);
	}
 
	void c(){
    	swap(A[1],A[28]);
    	swap(A[2],A[29]);
    	swap(A[3],A[30]);
    	swap(A[15],A[16]);
    	swap(A[19],A[21]);
	}
 
	void d(){
    	swap(A[7],A[22]);
    	swap(A[8],A[23]);
    	swap(A[9],A[24]);
    	swap(A[13],A[18]);
    	swap(A[10],A[12]);
	}


	void solve(int num){
  		int cnt=0, i;
  		
  		for(i=1;i<31;i++){
    	if(A[i]==B[i]) cnt++;
  		}
  		if(cnt==30) ans=num;
  		
  		if(ans<=num) return;
  	
  		a();solve(num+1);a();
 		b();solve(num+1);b();
		c();solve(num+1);c(); 
  		d();solve(num+1);d();
	}

	int main(){
		int n, j, k;
		scanf("%d", &n);
	
		for(j=0; j<n; j++){
			for(k=1; k<31; k++){
				scanf("%d", &A[k]);
			}		
			ans = 8;
			solve(0);
			printf("%d\n", ans);
		}
		return 0;
	}
