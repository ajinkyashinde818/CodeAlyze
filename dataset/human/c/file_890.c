#include<stdio.h>
#include<math.h>
long long primeFactorization(long long a,int num,int count[10000]){ //素因数分解を出力するプログラム
    long long i,sq;
    if(a%2==0){ //偶数の場合
      while(a%2==0){
        count[num]++;
        a/=2;
      }
      num+=1;
      return primeFactorization(a,num,count); //2で割った値で再帰
    }
    sq = sqrt(a);
    for(i=3;i<=sq;i+=2){ //3以上√a以下の奇数の場合
        if(a%i==0){
          while(a%i==0){
            count[num]++;
            a/=i;
          }
          num+=1;
          return primeFactorization(a,num,count); //割れた値で再帰
        }
    }
    //偶数でも3以上√a以下の奇数の場合でも割り切れない場合
    if(a!=1){ //aが1でないなら、a自身は素数
        count[num]=1;
        num+=1;
    }
    return num;
}
int main(){
    long long a;
    int num=0,sum=0,i,j,count[10000];
    scanf("%lld",&a);
    for(i=0;i<10000;i++)
      count[i]=0;
    num=primeFactorization(a,num,count);
    for(i=0;i<num;i++){
      j=1;
      while(count[i]-j>=0){
        sum++;
        count[i]-=j;
        j++;
      }
    }
    printf("%d\n",sum);
    return 0;
}
