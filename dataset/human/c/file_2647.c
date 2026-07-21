#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384
int max(int a,int b){if(a>b){return a;}return b;}
int min(int a,int b){if(a<b){return a;}return b;}
int zt(int a,int b){return max(a,b)-min(a,b);}
int gcd(int a,int b){int c;while(b!=0){c=a%b;a=b;b=c;}return a;}
int lcm(int a,int b){int c=gcd(a,b);a/=c;return a*b;}
int nCr(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
int nHr(int a,int b){return nCr(a+b-1,b);}
int fact(int a){int i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
int dsum(int x){int r=0;while(x){r+=(x%10);x/=10;}return r;}
int dsumb(int x,int b){int r=0;while(x){r+=(x%b);x/=b;}return r;}
int sankaku(int x){return ((1+x)*x)/2;}
void swap(int *a,int *b){int c;c=(*a);(*a)=(*b);(*b)=c;}
//小さい順
int compareInt(const void* a, const void* b){int aNum = *(int*)a;int bNum = *(int*)b;return aNum - bNum;}

int main(void){
    char a[3];
    scanf("%s",a);
    int a1=0,b=0,c=0;
    for(int i=0;i<3;i++){
        if(a[i]=='a'){
            a1++;
        }else if(a[i]=='b'){
            b++;
        }else if(a[i]=='c'){
            c++;
        }
     }
    if(a1*b*c==1){
        printf("Yes");
        return 0;
    }else{
        printf("No");
        return 0;
    }
}
