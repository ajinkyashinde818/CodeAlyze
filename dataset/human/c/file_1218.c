/*2019/10/02 */
/*template*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MOD 1000000007
#define MIN 999999999
#define MAX -999999999
typedef long long int ll;
typedef unsigned long long int ull;
void llswap(ll *x,ll *y){ll tmp;tmp=*x;*x=*y;*y=tmp;}
void swap(int *x,int *y){int tmp;tmp=*x;*x=*y;*y=tmp;}
void swap_c(char *x,char *y){char tmp;tmp=*x;*x=*y;*y=tmp;}
int rmax(int x,int y){return x>y?x:y;}
int rmin(int x,int y){return x>y?y:x;}
ll llrmax(ll x,ll y){return x>y?x:y;}
ll llrmin(ll x,ll y){return x>y?y:x;}
int asc(const void *a,const void *b){if(*(int*)a < *(int*)b)return -1;else if(*(int*)a == *(int*)b)return 0;else return 1;}
int desc(const void *a,const void *b){if(*(int*)a < *(int*)b)return 1;else if(*(int*)a == *(int*)b)return 0;else return -1;}
int llasc(const void *a,const void *b){if(*(ll*)a < *(ll*)b)return -1;else if(*(ll*)a == *(ll*)b)return 0;else return 1;}
int lldesc(const void *a,const void *b){if(*(ll*)a < *(ll*)b)return 1;else if(*(ll*)a == *(ll*)b)return 0;else return -1;}
int gcd(int x,int y){if(y==0)return x;return gcd(y,x%y);}
 
/*
int asc_t(const void *a,const void *b){if((pair_t*)a->d < (pair_t*)b->d)return -1;else if((pair_t*)a->d == (pair_t*)b->d)return 0;else return 1;}
int desc_t(const void *a,const void *b){if((pair_t*)a->d < (pair_t*)b->d)return 1;else if((pair_t*)a->d == (pair_t*)b->d)return 0;else return -1;}
*/

int main(){
    char s[200],t[200];
    scanf("%s",s);
    scanf("%s",t);

    for(int i=0;s[i+1]!='\0';i++){
        for(int j=i+1;s[j]!='\0';j++){
            if(s[i]>s[j]){
                swap_c(&s[i],&s[j]);
            }
        }
    }
    for(int i=0;t[i+1]!='\0';i++){
        for(int j=i+1;t[j]!='\0';j++){
            if(t[i]<t[j]){
                swap_c(&t[i],&t[j]);
            }
        }
    }
    
    printf("%s",strcmp(s,t)<0?"Yes\n":"No\n");
    return 0;
}
