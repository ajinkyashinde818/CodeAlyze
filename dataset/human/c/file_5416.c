#include <stdio.h>

long z(int *a,int *b,int *c,int *d){
    return ((long)b[0]-a[0])*(d[1]-c[1])-((long)d[0]-c[0])*(b[1]-a[1]);
}
int xx(int *a,int *b,int *c,int *d){
    long v,v1,v2;
    v=z(a,b,c,d);
    if(v==0)return 0;
    v1=z(a,c,a,b);
    v2=z(a,c,c,d);
    if(v<0){
        v=-v;
        v1=-v1;
        v2=-v2;
    }
    return 0<=v1&&v1<=v&&0<=v2&&v2<=v;
}
int x(int (*a)[8],int (*b)[8]){
    int i,j;
    int *c,*d,*e,*f;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            c=&(*a)[i*2];
            d=&(*a)[(i*2+2)%8];
            e=&(*b)[j*2];
            f=&(*b)[(j*2+2)%8];
            if(z(e,f,e,c)>0)break;
        }
        if(j==4)return 1;
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            c=&(*b)[i*2];
            d=&(*b)[(i*2+2)%8];
            e=&(*a)[j*2];
            f=&(*a)[(j*2+2)%8];
            if(z(e,f,e,c)>0)break;
        }
        if(j==4)return 1;
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            c=&(*a)[i*2];
            d=&(*a)[(i*2+2)%8];
            e=&(*b)[j*2];
            f=&(*b)[(j*2+2)%8];
            if(xx(c,d,e,f))return 1;
        }
    }
    return 0;
}

int main(){
    int n,m;
    int a[100],l[100][8],b[100];
    int i,j,k;
    int min,ii,jj,kk;
    while(scanf("%d",&n)&&n){
        while(n--){
            scanf("%d",&m);
            for(i=0;i<m;i++){
                a[i]=i;
                for(j=0;j<8;j++)scanf("%d",&l[i][j]);
            }
            for(i=0;i<m;i++){
                for(j=i+1;j<m;j++){
                    if(x(&l[i],&l[j])){
                        k=0;
                        ii=i;
                        while((b[k++]=ii),a[ii]!=ii)ii=a[ii];
                        jj=j;
                        while((b[k++]=jj),a[jj]!=jj)jj=a[jj];
                        min=ii<jj?ii:jj;
                        for(kk=0;kk<k;kk++)a[b[kk]]=min;
                    }
                }
            }
            for(i=0;i<m;i++){
                j=i;
                while(a[j]!=j)j=a[j];
                a[i]=j;
            }
            k=0;
            for(i=0;i<m;i++){
                for(j=0;j<i;j++){
                    if(a[i]==a[j])break;
                }
                if(j==i)k++;
            }
            printf("%d\n",k);
        }
    }
    return 0;
}
