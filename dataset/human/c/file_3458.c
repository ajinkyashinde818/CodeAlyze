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

int W_Length(char *str){
	int length = 0;
	while(*str++ != '\0')
		length++;
	return length;
}

void swap(int *a, int *b){
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}
//swap(&a, &b)

double deg(double theta){//deg to theta
return theta*(2*3.14159265359)/360;
}

int cmp( const void *p, const void *q ) {
    return *(int*)p - *(int*)q;
}//ちいさい順
//qsort(a,n,sizeof(int),cmp);
//char s[n][11]

int cmp_s(const void * left, const void * right)
{
	char *left_char = (char *)left;
  char *right_char = (char *)right;
  return strcmp(left_char, right_char);
}
//qsort(s,n,sizeof(s[0]),cmp_s);


int main (void)
{
	long long int a[210000],b,c,j,n,k,i,check[210000]={0},flag=0,count=1;
  char s[200005];

scanf("%lld%lld",&n,&k);
	for(i=1;i<=n;i++){
scanf("%lld",&a[i]);
	}
  i=1;
    check[1]=1;
  while(k>0){
    i=a[i];
    check[i]++;
//    printf("%lld,k=%lld\n",i,k);
    k--;
    
    if(check[i]==3){
      flag=1;
      for(j=1;j<=n;j++){
      if(check[j]==2){
      count++;
      }
      }
            break;
      
    }
  }
  k=k%count;
    while(k>0){
    i=a[i];
//      printf("2=%lld,k=%lld\n",i,k);
    check[i]++;
    k--;
    }
  
  printf("%lld",i);
  return 0;
}
