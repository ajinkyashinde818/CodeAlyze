#include<stdio.h>
#include<stdlib.h>

int main(){
  int h,w,k;
  scanf("%d%d%d\n",&h,&w,&k);
  char c[h][w];//character
  int ou[h][w];//output
  char st[h];//strawberry in each row
  int no=1; //block no.
  int fir=0; //first element in row?

  //copy elements
  for(int i=0;i<h;i++){
    st[i]=0;
    for(int j=0;j<w;j++){
      scanf("%c",&c[i][j]);
      if(c[i][j]=='#'){
	st[i]+=1;}}
    if(i==h-1) break;
    scanf("\n");
  }

  int n=0;
  while(st[n]==0){
    n++;}
   for(int i=n;i<h;i++){
     fir=0;
     
     //if there is no strawberry
     if(st[i]==0){
       for(int l=0;l<w;l++){
	 ou[i][l]=ou[i-1][l];}
       continue;}
     //
     for(int j=0;j<w;j++){
       //if there was a strawberry
       if(c[i][j]=='#'){
	 //if first
	 if(fir==0){
	   fir=1;}
	 else{
	   no+=1;}}
       ou[i][j]=no;}
     
     no+=1;}

   for(int m=n-1;m>=0;m--){
     for(int j=0;j<w;j++){
       ou[m][j]=ou[m+1][j];}}

   for(int i=0;i<h;i++){
     for(int j=0;j<w;j++){
       printf("%d ",ou[i][j]);}
     printf("\n");}
  
  return 0;
}
