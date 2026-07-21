#include <cstdio>

using namespace std ;

int R,G,B,N ;

int ans = 0 ;

void fb(int sum) ;

void fg(int sum){
		while(sum<=N){
			fb(sum) ;
			sum += G ;
		}
	}
void fr(){
		int sum = 0 ;
		while(sum<=N){
			fg(sum) ;
			sum += R ;
		}
	}
void fb(int sum){
			if((N-sum)%B==0){
				ans++ ;
			}
			//sum += B ;

	}



int main(){
    scanf("%d %d %d %d",&R,&G,&B,&N) ;
    fr() ;
    printf("%d",ans) ;
    return 0 ;
}
