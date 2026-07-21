#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//if(strcmp(s[i],"AC")==0)
//if(s[l]=='#')
/*小文字判定
if((moji>= 'a') && (moji<='z')){
    printf("a\n");
    return 0;
  }
  */
//文字列中の一文字⇒数字の時は s[i]-'0'
int W_Length(char *str){
	int length = 0;
	while(*str++ != '\0')
		length++;
	return length;
}

void swap(long long int *a, long long int *b){
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}
//swap(&a, &b)

double deg(double theta){//deg to theta
return theta*(2*3.14159265359)/360;
}

long long int cmp( const void *p, const void *q ) {
    return *(long long int*)p - *(long long int*)q;
}//ちいさい順
//qsort(a,n,sizeof(long long int),cmp);


int cmp_s(const void * left, const void * right)
{
	char *left_char = (char *)left;
  char *right_char = (char *)right;
  return strcmp(left_char, right_char);
}
//qsort(s,n,sizeof(s[0]),cmp_s);
//char s[n][11]

long long int GCD(long long int a, long long int b){
  long long int L=a,S=b;
  while(1){
    if(S>L){
      L=S+L;
      S=L-S;
      L=L-S;
    }
    if(L%S==0){
      return S;
    }
    L=L%S;
  }
  
}

long long int LCM(long long int a, long long int b){
  return a*b/(GCD(a,b));
}

int main (void)
{
	long long int n,m,k,x,i,min=100000000, a[13][13],l,max,j,temp=0,c[13]={0},sum_n[13]={0},sum_cost,flag;
scanf("%lld%lld%lld",&n,&m,&x);
for(i=1;i<=n;i++){
  scanf("%lld",&c[i]);
  for(j=1;j<=m;j++){
    
  scanf("%lld",&a[i][j]);
}  
}

  for(i=1;i<=4095;i++){
k=i;
sum_cost=0;
    for(l=1;l<=m;l++){
        sum_n[l]=0;
      }

    for(j=1;j<=n;j++){
          temp=k%2;
    k=k/2;
      for(l=1;l<=m;l++){
        sum_n[l]+=a[j][l]*temp;
      }
      sum_cost+=c[j]*temp;
    }
    flag=1;
    for(j=1;j<=m;j++){
      if(sum_n[j]<x){
        flag=0;
        break;
      }
    }
    if(flag==1&&min>=sum_cost){
      min=sum_cost;
    }
  }
  if(min==100000000){
    printf("-1");
    return 0;
  }
  printf("%lld",min);
return 0;
  }
