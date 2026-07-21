#include<stdio.h>
struct no
{  int p,l,r;
};
no a[1000];
int n,root;
int max(int a,int b)//比大小 
{  if(a>=b)  return a;
   else return b;
}
int de(int u)//求深度 
{  int d=0;
   if(u==root) return 0;
   while(a[u].p!=-1)
   {  u=a[u].p;
	  d++;
   }
   return d;
}
int pp(int u)//求父结点 
{  if(a[u].p!=-1)  return a[u].p;
   else return -1;
}
int hh(int u)//求高度 
{  if(u==-1)  return 0;
   if(a[u].l==-1&&a[u].r==-1) return 1;
   return max(hh(a[u].l),hh(a[u].r))+1;
}
int bro(int u)//求兄弟结点 
{  int t=u;
   if(a[u].p!=-1)  u=a[u].p;
   else return -1;
   if(a[u].l==t&&a[u].r!=-1)  return a[u].r;
   else if(a[u].l!=t&&a[u].r!=-1)  return a[u].l;
   else if(a[u].l==t&&a[u].r==-1)  return -1;
   else if(a[u].r==t&&a[u].l==-1)  return -1;
}
int kind(int u)
{  if(u==root)  return 1;//根 
   else if(a[u].p!=-1&&(a[u].l!=-1||a[u].r!=-1)) return 2;//内部
   else if(a[u].l==-1&&a[u].r==-1)   return 3;//叶 
}
int gg(int u)
{  if(a[u].l==-1&&a[u].r==-1)  return 0;
   else if(a[u].l!=-1&&a[u].r!=-1)  return 2;
   else return 1;
}
int main()
{  int i,t,v,r,l;
   scanf("%d",&n);
   for(i=0;i<n;i++)
     a[i].p=-1;
   for(i=0;i<n;i++)
   {  scanf("%d%d%d",&v,&l,&r);
      a[v].l=l;
      a[v].r=r;
      if(l!=-1)  a[l].p=v;
      if(r!=-1)  a[r].p=v;
   }
   for(i=0;i<n;i++)//求根结点 
     if(a[i].p==-1)  root=i;
   for(i=0;i<n;i++)
   {  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, "
      ,i,pp(i),bro(i),gg(i),de(i),hh(i)-1);
      if(kind(i)==1)  printf("root\n");
      else if(kind(i)==2)  printf("internal node\n");
      else if(kind(i)==3)  printf("leaf\n");
   }
   return 0;
}
