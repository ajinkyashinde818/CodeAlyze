#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
typedef long long LL;
const int e[40]={0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,
                 5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8};
const int mp[16]={1,3,5,7,11,15,21,33,35,55,77,105,165,231,385,1155};
const int results[16]={1,0,0,0,0,3,3,3,5,5,7,3,3,3,5,3};
const LL UnUseMethod=4759123141;
const unsigned long ULONG=18446744073709551615U;
int sz=0;LL count[2]={0},Box[10]={0};
LL IN(void)
{
  LL x=0;short f=0,c=getchar();while(c<48||c>57){f^=c==45,c=getchar();}
  while(c>47&&c<58){x=x*10+c-48,c=getchar();}return f?-x:x;
}
inline LL GCD(LL a,const LL b){return !b?a:GCD(b,a%b);}
inline LL Mult(const LL x,const LL y,const LL mod)
{LL z=x*y-(LL)((long double)x/mod*y+1e-8)*mod;return z<0?z+mod:z;}
inline LL BinaryModularPower(LL base,LL pow,const LL mod)
{
  LL x=1;
  while(pow){if(pow&1){x=Mult(x,base,mod);}base=Mult(base,base,mod);pow>>=1;}
  return x;
}
void Exp(LL x,const LL y)
{count[1]=0;if(!y){return;}while(!(x%y)){count[1]++;x/=y;}count[0]=x;return;}
inline LL Pseudo(const LL x){return (LL)((long double)pow(x,0.5));}
inline int PerfectSquare(const LL x){if(x<0)return 0;else{LL y=Pseudo(x);return x==y*y;}}
inline int PerfectCube(const LL x){LL z=(LL)cbrt(x);return x==z*z*z;}
int MillerRabin(const LL a)
{
  /*http://www.olivierlanglois.net/archive/prime_cpp.htm*/
  if(a==2)return 1;
  if((a&1)==0||a<2)return 0;
  if(PerfectSquare(a))return 0;
  if(PerfectCube(a))return 0;
  static const int pr[7]={2,325,9375,28178,450775,9780504,1795265022};
  LL odd=a-1,k=0,p=1,x;
  while(!(odd&1)){odd>>=1;k++;}
  for(int i=0;i<7;++i)
  {
    p=(LL)(pr[i]%a);
    if(!p)return 1;
    x=BinaryModularPower(p,odd,a);
    if(x==1||x==a-1)return 1;
    for(int j=0;j<k;j++)
    {
      x=BinaryModularPower(x,2,a);
      if(x==a-1)return 1;
    }
  }
  return 0;
}
LL iter(const LL x,const int k,const int lim,const int divisor)
{
  static int i,j;
  LL bits,cutoff,p0=0,q0=1,p1,q1,Q,rootQ=0,sq=Pseudo(k*x),temp=GCD(k,x);
  cutoff=Pseudo(2*sq)/divisor,p1=sq;q1=(k*x-p1*p1);
  if(temp!=1)return temp;
  if((k*x)>>62)return 1;
  if(!q1){temp=GCD(x,p1);return temp==x?1:temp;}
  for(i=0;i<lim;i++)
  {
    temp=sq+p1-q1,Q=1;
    if(temp>=q1)Q+=temp/q1;
    p0=Q*q1-p1;q0=q0+Q*(p1-p0);
    if(q1<2*k*cutoff){temp=q1/GCD(q1,2*k);if(temp<cutoff)Box[sz++]=temp;}
    bits=0,temp=q0;
    while(!(temp&1)){bits++,temp>>=1;}
    if(!(bits&1)&&((temp&7)==1))
    {
      rootQ=Pseudo(q0);
      if(PerfectSquare(q0))
      {
        for(j=0;j<sz;++j){if(Box[j]==rootQ)break;}
        if(j==sz)break;
      }
    }
    temp=sq+p0-q0,Q=1;
    if(temp>=q0){Q+=temp/q0;}
    p1=Q*q0-p0,q1=q1+Q*(p0-p1);
    if(q0<2*k*cutoff){temp=q0/GCD(q0,2*k);if(temp<cutoff)Box[sz++]=temp;}
  }
  if(rootQ==1)return 1;
  if(i==lim)return 1;
  q0=rootQ,p1=p0+rootQ*((sq-p0)/rootQ);
  q1=(k*x-p1*p1)/q0;
  for(j=0;j<lim;j++)
  {
    Q=1,temp=sq+p1-q1;
    if(temp>=q1)Q+=temp/q1;
    p0=Q*q1-p1,q0=q0+Q*(p1-p0);
    if(p0==p1){q0=q1;break;}
    temp=sq+p0-q0,Q=1;
    if(temp>=q0)Q+=temp/q0;
    p1=Q*q0-p0,q1=q1+Q*(p0-p1);
    if(p0==p1)break;
  }
  temp=GCD(q0,x);
  if(temp==x)temp=1;
  return temp;
}
inline LL SQUFOF(const LL x)
{
  LL y;
  if(MillerRabin(x))return x;
  if(PerfectSquare(x))return Pseudo(x);
  if(PerfectCube(x))return (LL)cbrt(x);
  for(int i=1;i<20000;i*=4)
  {
    for(int k=0;k<16;k++)
    {
      if(x==mp[k])return results[k];
      if(ULONG/mp[k]<=(unsigned long)x)continue;
      y=iter(x,mp[k],300*i,1);
      if(y==1||y==x)continue;
      return y;
    }
  }
  return 1;
}
inline LL PollardRho(const LL n,const LL a)
{
  if(MillerRabin(n))return n;
  if(PerfectSquare(n))return Pseudo(n);
  if(PerfectCube(n))return (LL)cbrt(n);
  LL x=rand()%n,y=x;static LL gcd=1,k=0,i=1;
  while(gcd==1)
  {
    k++;
    x=Mult(x,x,n)+a;if(x>=n)x-=n;
    gcd=GCD(x>y?x-y:y-x,n);
    if(k==i){y=x;i<<=1;}
  }
  if(gcd==n)return PollardRho(n,a+1);
  return gcd;
}
signed main(void)
{
  LL a=0,p=1,q=-1,N=IN();
  if(N<=1)return puts("0"),0;
  Exp(N,2);a=e[count[1]];N=count[0];
  Exp(N,3);a+=e[count[1]];N=count[0];
  while(q*q<=UnUseMethod)
  {
    p+=6,q+=6;
    Exp(N,p);a+=e[count[1]];N=count[0];
    Exp(N,q);a+=e[count[1]];N=count[0];
  }
  if(N<=UnUseMethod){if(N>1){a++;}return printf("%lld\n",a),0;}
  if(MillerRabin(N)){a++;return printf("%lld\n",a),0;}
  srand((unsigned int)time(NULL));
  while(N>=UnUseMethod)
  {
    p=SQUFOF(N);
    while(p<q)p=SQUFOF(N);
    while(!MillerRabin(p))p=PollardRho(N,p);
    Exp(N,p);a+=e[count[1]];N=count[0];
  }
  if(MillerRabin(N)){a++;}return printf("%lld\n",a),0;
}
