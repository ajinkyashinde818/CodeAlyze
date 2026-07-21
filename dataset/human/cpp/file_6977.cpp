#include<bits/stdc++.h>
using namespace std;

long long ara[200002],tra[200002];

int main()
{

    long long n,m,i,j,k,a,b,c,st=-1,fn=-1,flg=1,p,q,x,y,tlg;
    vector<long long>u,v;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&a); v.push_back(a); ara[a]++;
    }

    for(i=0;i<n;i++)
    {
        scanf("%lld",&a); u.push_back(a); tra[a]++;
    }

    for(i=1;i<=n;i++)
    {
        if(ara[i]!=0)
        {
            if(ara[i]+tra[i]>n){ flg=0; break;  }
        }

    }


    if(flg==1)
    {

        reverse(u.begin(),u.end());

        for(i=0;i<n;i++)
        {
            if(v[i]==u[i])
            {
                if(st==-1){  st=i; }

                fn=i;
            }

        }

        if(st!=-1)
        {

            p=st-1; q=fn+1;

            for(i=st;i<=fn;i++)
            {
                x=v[i]; tlg=0;

                for(j=q;j<n;j++)
                {

                    q=j+1;

                    if(v[j]!=x && u[j]!=x)
                    {
                        u[i]=u[j];  u[j]=x; tlg=1; break;
                    }

                }

                if(tlg==0)
                {
                    for(j=p-1;j>=0;j--)
                    {
                        p=j-1;

                        if(v[j]!=x && u[j]!=x)
                        {
                            u[i]=u[j]; u[j]=x; tlg=1; break;
                        }
                    }
                }

                if(tlg==0){  flg=0; break; }

            }

        }


    }


    if(flg==0)printf("No\n");
    else
    {
        printf("Yes\n");

        for(i=0;i<n;i++)
        {
            printf("%lld ",u[i]);
        }


    }




    return 0;
}
