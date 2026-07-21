#include <stdio.h>

int main() {
  int R,G,B,N,r,g,b,count=0,balls,i,j,number[3],tmp;
  scanf("%d%d%d%d",&number[0],&number[1],&number[2],&N);
  for(i=0;i<3;i++){
    for(j=i+1;j<3;j++){
      if(number[i]>number[j]){
	tmp=number[i];
	number[i]=number[j];
	number[j]=tmp;
      }
    }
  }
  R=number[2];
  G=number[1];
  B=number[0];
  for(r=0;r<=N/R;r++){
    for(g=0;g<=N/G;g++){

      balls=R*r+G*g;
      b=(N-balls)/B;
      //printf("%d %d %d\n",b,g,r);
      if(b>=0){
	if(balls+B*(b-1)==N){
	  count++;
	}
	else if(balls+B*b==N){
	  count++;
	}
	else if(balls+B*(b+1)==N){
	  count++;
	}
      }
      
      /*
      for(b=0;b<=N/B;b++){
	balls=R*r+G*g+B*b; 
	if(balls==N){
	  count++;
	}
	else if(balls>N){
	  break;
	}
      }
      */
    }
  }
  
  printf("%d\n",count);
  return 0;
}
