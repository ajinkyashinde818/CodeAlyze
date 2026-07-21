#if 0
#include <stdio.h>
//复杂度为n^2的算法
int main()
{
    int n;
    int A[2000010];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int max=A[1]-A[0];
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        for(;j<n;j++)
        {
           if(A[j]-A[i]>max)max=A[j]-A[i];
        }
    }
    printf("%d\n",max);
    return 0;
}
#elif 0
#include<stdio.h>
int main()
{
    int i,n,a[200010],ans,min;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    min=a[0];
    ans=a[1]-a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]<min) min=a[i];
        else if(a[i]-min>ans) ans=a[i]-min;
    }
    printf("%d\n",ans);
    return 0;
}

#elif 0
#include<stdio.h>
int main()
{
    int n,min,max,m,m2;
    scanf("%d%d%d",&n,&m,&m2);
    min=m;
    max=m2-min;
    for(int i=2;i<n;i++)
    {
        scanf("%d",&m);
        if(m-min>max)max=m-min;
        if(m<min)min=m;
        printf("min=%d max=%d\n",min,max);
    }
    printf("%d\n",max);
   return 0;
}
#elif 1

#include <stdio.h>
int main()
{
    int A[200010],n,min,max;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    min=A[0];
    max=A[1]-min;
    for(int i=1;i<n;i++)
    {
        if(A[i]-min>max)max=A[i]-min;
        if(A[i]<min)min=A[i];
    }
    printf("%d\n",max);
    return 0;
}

#endif
/*
20
100
99
95
86
85
76
75
71
70
61
52
48
47
43
42
38
37
33
32
28
*/
