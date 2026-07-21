#include<stdio.h>
int n;
int pa[100001],si[100001],de[100001];
int cald(int i);
int calh(int i);
int main() {
  int i,j;
  scanf("%d", &n);
  for(i=0;i<n;i++) {
    pa[i] = -1;
    si[i] = -1;
    de[i] = 0;
  }
  for(i=0;i<n;i++) {
    int id, left, right;
    scanf("%d %d %d", &id, &left, &right);
    if(left != -1) {
      pa[left] = id;
      si[left] = right;
      ++de[id];
    }
    if(right != -1) {
      pa[right] = id;
      si[right] = left;
      ++de[id];
    }
  }
  for(i=0;i<n;i++) {
    int dep;
    dep=cald(i);
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height\
\
 = %d, ",i, pa[i], si[i], de[i], dep, calh(i));
    if(dep== 0) printf("root\n");
    else if(de[i] == 0) printf("leaf\n");
    else printf("internal node\n");

  }
  return 0;
}
int cald(int s){
  if(pa[s]==-1)return 0;
  return cald(pa[s])+1;
}
int calh(int s){
  int i,h=0;
  for(i=0;i<n;i++){
    if(pa[i]==s){
      int tmp;
      tmp=calh(i)+1;
      if(tmp>h)h=tmp;
    }
  }
  return h;
}
