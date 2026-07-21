#include<stdio.h>

void quick(int *,int,int);

int main(){

int N;
scanf("%d",&N);
int member = 3*N;
int a[member];

for (int i = 0; i < member; i++){
    scanf("%d",&a[i]);
}

quick(a,0,member-1);

long long ans=0;
for (int i = member-2; i >= N; i-=2)
{
  ans += a[i];
}

printf("%lld",ans);

return 0;

}
void quick(int a[],int left,int right)
{
    int s,t,i,j;

    if (left<right){
        s=a[left];
        i=left; j=right+1;
        while (1){         
            while (a[++i]<s);
            while (a[--j]>s);
            if (i>=j) break;
            t=a[i]; a[i]=a[j]; a[j]=t;
        }
        a[left]=a[j]; a[j]=s;

        quick(a,left,j-1);
        quick(a,j+1,right);
    }
}
