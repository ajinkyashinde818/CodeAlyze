#include<bits/stdc++.h>
using namespace std;

int N; long long L;
struct Node
{
  bool p;
  Node* L;
  Node* R;
}; Node* root;

long long calc(Node* r, long long h)
{
  if(!r) return h&(-h);
  if(r->p) return 0;
  return calc(r->L, h-1)^calc(r->R, h-1);
}
void ins(Node* r, char* s)
{
  if(*s == 0){r->p = true; return;}
  if(*s == '0')
  {
    if(!(r->L))
    {
      r->L = new Node();
    }
    ins(r->L, s+1);
  }
  else
  {
    if(!(r->R))
    {
      r->R = new Node();
    }
    ins(r->R, s+1);
  }
}

char s[101010];
int main()
{
  root = new Node();
  scanf("%d%lld", &N, &L);
  for(int i=0; i<N; ++i)
  {
    scanf("%s", s);
    ins(root, s);
  }
  puts(calc(root, L+1)?"Alice":"Bob");
  return 0;
}
