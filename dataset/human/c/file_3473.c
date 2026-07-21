#include<stdio.h>
#include<string.h>
int main() {
    int n;
    long long k;scanf("%d %llu",&n,&k);
    int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);
    
    int next=0;
    int cnt=0;
    int table[600000]={};
    static int proc[600000]={};
    proc[0]=1;
    table[0]++;
    int flg;
    for(int i=0;i<2*n;i++){
        int next = a[next] - 1;
        proc[i+1]=next+1;
        if(table[next]>=1){flg=next+1;break;}
        
        table[next]++;
    }
    fprintf(stderr,"flg:%d\n", flg);
    int start=-1,end=-1;
    for(int i=0;i<2*n;i++){
        fprintf(stderr,"%d ",proc[i]);
        if(proc[i]==flg){
            if(start==-1)start=i;
            else if(end==-1)end=i;
        }
        if(end!=-1)break;
    }
    fprintf(stderr,"\n");
    int range = end-start;
    fprintf(stderr, "%d %d %d\n",start,end,range);

    int c=0;
    if(flg==1){
        c=0;
    }else{
        for(int i=1;i<n;i++){
            if(proc[i]==flg){
                c=i;
                break;
            }
        }
    }
    fprintf(stderr,":%d\n",c);
    fprintf(stderr,"::%lld\n",(k-c));
    if(k-c<0)printf("%d\n",proc[k]);
    else printf("%d\n",proc[c+(k-c)%range]);
}
